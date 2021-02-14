/*
** EPITECH PROJECT, 2020
** load_transform_component.c
** File description:
** load_transform_component.c
*/

#include "utils/init/entity/components/transform/load_transform_component_tabs.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../../../include/my.h"
#include "my_puterr.h"

void load_transform_position(char *content, int *i, transform_t *transform)
{
    char *path = extract_value(content, i);
    char **pos = my_str_to_tab(path, ' ');;
    int j = 0;

    if (pos == NULL)
        my_puterr("Malloc error in my_str_to_tab", __FILE__, __LINE__);
    for (; pos[j]; j++);
    if (j != 2)
        my_puterr("Incorrect position coords", __FILE__, __LINE__);
    transform->position.x = (float)my_getnbr(pos[0]);
    transform->position.y = (float)my_getnbr(pos[1]);
    free(path);
    free(pos[0]);
    free(pos[1]);
    free(pos);
}

void load_transform_scale(char *content, int *i, transform_t *transform)
{
    char *path = extract_value(content, i);
    char **pos = my_str_to_tab(path, ' ');;
    int j = 0;

    if (pos == NULL)
        my_puterr("Malloc error in my_str_to_tab", __FILE__, __LINE__);
    for (; pos[j]; j++);
    if (j != 2)
        my_puterr("Incorrect scale values", __FILE__, __LINE__);
    transform->scale.x = (float)my_getnbr_f(pos[0]);
    transform->scale.y = (float)my_getnbr_f(pos[1]);
    free(path);
    free(pos[0]);
    free(pos[1]);
    free(pos);
}

void load_transform_velocity(char *content, int *i, transform_t *transform)
{
    char *path = extract_value(content, i);
    char **pos = my_str_to_tab(path, ' ');;
    int j = 0;

    if (pos == NULL)
        my_puterr("Malloc error in my_str_to_tab", __FILE__, __LINE__);
    for (; pos[j]; j++);
    if (j != 2)
        my_puterr("Incorrect velocity values", __FILE__, __LINE__);
    transform->velocity.x = (float)my_getnbr(pos[0]);
    transform->velocity.y = (float)my_getnbr(pos[1]);
    free(path);
    free(pos[0]);
    free(pos[1]);
    free(pos);
}

void load_transform_speed(char *content, int *i, transform_t *transform)
{
    char *path = extract_value(content, i);

    transform->speed = my_getnbr_f(path);
    free(path);
}

void load_transform_component(char *content, int *i, components_t *components)
{
    components->transform = malloc_transform();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</transform>", 12)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (transform_conf_tag_action[k].tag && my_strncmp(content + *i,
        transform_conf_tag_action[k].tag, transform_conf_tag_action[k].tag_len))
            k++;
        if (!transform_conf_tag_action[k].tag)
            my_puterr("Unrecognized transform tag", __FILE__, __LINE__);
        *i += transform_conf_tag_action[k].tag_len;
        transform_conf_tag_action[k].action(content, i, components->transform);
        *i += transform_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}