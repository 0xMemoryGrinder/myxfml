/*
** EPITECH PROJECT, 2020
** load_scene_list.c
** File description:
** header for load_scene_list.c
*/

#include "my_csfml.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init_xfml.h"


#define SCENE_PATH "conf/scenes/"

void get_scenes_list(char *content, int *i, game_data_t *data)
{
    int j = 0;
    char *name = NULL;
    char *path;
    char *path2;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</list>", 7)) {
        skip_to_next_tag(content, i, OPEN);
        *i += 7;
        name = extract_value(content, i);
        *i += 8;
        path = my_strcat(SCENE_PATH, name);
        path2 = my_strcat(path, "/.xml");
        load_scene(path2, j, data);
        j++;
        free(name);
        free(path);
        free(path2);
        skip_to_next_tag(content, i, NEXT);
    }
}

void get_actual_scene_id(char *content, int *i, game_data_t *data)
{
    char *scene_id = extract_value(content, i);

    data->scenes->actual = my_getnbr(scene_id);
    free(scene_id);
}

void get_scenes_count(char *content, int *i, game_data_t *data)
{
    char *scene_id = extract_value(content, i);

    data->scenes->count = my_getnbr(scene_id);
    data->scenes->list = malloc_scene_array(data->scenes->count);
    free(scene_id);
}

void get_game_scenes(char *content, int *i, game_data_t *data)
{
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</scenes>", 9)) {
        skip_to_next_tag(content, i, OPEN);
        k = 0;
        while (scene_conf_tags[k].tag && my_strncmp(content + *i,
        scene_conf_tags[k].tag, scene_conf_tags[k].tag_len))
            k++;
        if (!scene_conf_tags[k].tag)
            my_puterr("Unrecognized scene tag", __FILE__, __LINE__);
        *i += scene_conf_tags[k].tag_len;
        scene_conf_tags[k].action(content, i, data);
        *i += scene_conf_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}