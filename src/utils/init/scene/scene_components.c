/*
** EPITECH PROJECT, 2020
** scene_components.c
** File description:
** header for scene_components.c
*/

#include "utils/init_xfml.h"
#include "my.h"
#include "my_csfml.h"


void get_scene_name(char *content, int *i, scene_id id, game_data_t *data)
{
    data->scenes->list[id].name = extract_value(content, i);
}

void get_scene_toggle(char *content, int *i, scene_id id, game_data_t *data)
{
    toggle_t t = fill_toogle(content, i);
    data->scenes->list[id].toggle = t;
}

void get_scene_background(char *content, int *i,
scene_id id, game_data_t *data)
{
    char *path = extract_value(content, i);

    data->scenes->list[id].objects->background = load_entity(path, NULL);
}


void init_entities_list(char *content, int *i, scene_id id, game_data_t *data)
{
    int count = 0;
    char *name = NULL;
    int j = 0;
    entity_t *entity = NULL;

    data->scenes->list[id].objects->list = malloc_entity_node();
    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</entities>", 11)) {
        skip_to_next_tag(content, i, OPEN);
        *i += 15;
        count = my_getnbr(content + *i);
        while (content[*i] != '>')
            *i += 1;
        *i += 1;
        name = extract_value(content, i);
        for (j = 0; j < count; j++) {
            entity = load_entity(name, NULL);
            add_entity(entity, &data->scenes->list[id].objects->list);
        }
        *i += 9;
        skip_to_next_tag(content, i, NEXT);
    }
}