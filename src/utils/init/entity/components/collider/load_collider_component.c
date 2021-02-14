/*
** EPITECH PROJECT, 2020
** load_collider_component.c
** File description:
** load_collider_component.c
*/

#include <stdlib.h>
#include "utils/init/entity/components/collider/load_collider_component_tabs.h"
#include "my_csfml.h"
#include "utils/init/load_file.h"
#include "my.h"
#include "utils/init/common_tags.h"
#include "my_puterr.h"

void load_collider_toggle(char *content, int *i, collider_t *collider)
{
    collider->toggle = fill_toogle(content, i);
}

void load_collider_position(char *content, int *i, collider_t *collider)
{
    char *path = extract_value(content, i);
    char **pos = my_str_to_tab(path, ' ');;
    int j = 0;

    if (pos == NULL)
        my_puterr("Malloc error in my_str_to_tab", __FILE__, __LINE__);
    for (; pos[j]; j++);
    if (j != 2)
        my_puterr("Incorrect position coords", __FILE__, __LINE__);
    collider->position.x = (float)my_getnbr(pos[0]);
    collider->position.y = (float)my_getnbr(pos[1]);
    free(path);
    free(pos[0]);
    free(pos[1]);
    free(pos);
}

void load_collider_dimensions(char *content, int *i, collider_t *collider)
{
    char *path = extract_value(content, i);
    char **pos = my_str_to_tab(path, ' ');;
    int j = 0;

    if (pos == NULL)
        my_puterr("Malloc error in my_str_to_tab", __FILE__, __LINE__);
    for (; pos[j]; j++);
    if (j != 2)
        my_puterr("Incorrect dimensions values", __FILE__, __LINE__);
    collider->dimensions.x = (float)my_getnbr(pos[0]);
    collider->dimensions.y = (float)my_getnbr(pos[1]);
    free(path);
    free(pos[0]);
    free(pos[1]);
    free(pos);
}

void load_collider_action(char *content, int *i, collider_t *collider)
{
    collider->on_collison =  (void (*)(entity_list_t *, entity_list_t *,
    game_data_t *, sfIntRect)) fill_function(content, i,
    collider_func_ptr_tab);
}

void load_collider_component(char *content, int *i, components_t *components)
{
    components->collider = malloc_collider();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</collider>", 11)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (collider_conf_tag_action[k].tag && my_strncmp(content + *i,
        collider_conf_tag_action[k].tag, collider_conf_tag_action[k].tag_len))
            k++;
        if (!collider_conf_tag_action[k].tag)
            my_puterr("Unrecognized collider tag", __FILE__, __LINE__);
        *i += collider_conf_tag_action[k].tag_len;
        collider_conf_tag_action[k].action(content, i, components->collider);
        *i += collider_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}