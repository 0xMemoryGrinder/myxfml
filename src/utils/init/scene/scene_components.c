/*
** EPITECH PROJECT, 2020
** scene_components.c
** File description:
** header for scene_components.c
*/

#include <sys/stat.h>
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

    char *name = extract_value(content, i);
    char *path = my_strcat("conf/scenes/", data->scenes->list[id].name);
    char *path2 = my_strcat(path, "/");
    char *path3 = my_strcat(path2, name);
    char *path4 = my_strcat(path3, ".xml");
    data->scenes->list[id].objects->background = load_entity(path4, NULL);
    free(path);
    free(name);
    free(path2);
    free(path3);
    free(path4);
}


void init_entities_list(char *content, int *i, scene_id id, game_data_t *data)
{
    int count = 0;
    char *name = NULL;
    int j = 0;
    entity_t *entity = NULL;
    char *path = my_strcat("conf/scenes/", data->scenes->list[id].name);
    char *path2 = my_strcat(path, "/");
    char *path3 = NULL;
    char *path4 = NULL;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</entities>", 11)) {
        skip_to_next_tag(content, i, OPEN);
        *i += 15;
        count = my_getnbr(content + *i);
        while (content[*i] != '>')
            *i += 1;
        *i += 1;
        name = extract_value(content, i);
        path3 = my_strcat(path2, name);
        path4 = my_strcat(path3, ".xml");
        for (j = 0; j < count; j++) {
            entity = load_entity(path4, NULL);
            add_entity(entity, &data->scenes->list[id].objects->list);
        }
        free(name);
        free(path3);
        free(path4);
        *i += 9;
        skip_to_next_tag(content, i, NEXT);
    }
}