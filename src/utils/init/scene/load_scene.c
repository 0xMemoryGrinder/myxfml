/*
** EPITECH PROJECT, 2020
** load_scene.c
** File description:
** header for load_scene.c
*/

#include "my_puterr.h"
#include "my_csfml.h"
#include "my.h"
#include "utils/init_xfml.h"

void get_scene(char *content, int *i, game_data_t *data, scene_id id)
{
    int k;

    while (my_strncmp(content + *i, "</scene>", 9)) {
        skip_to_next_tag(content, i, false);
        k = 0;
        while (scene_tags[k].tag && my_strncmp(content + *i,
        scene_tags[k].tag, scene_tags[k].tag_len))
            k++;
        if (!scene_tags[k].tag)
            my_puterr("Unrecognized scene tag", __FILE__, __LINE__);
        *i += scene_tags[k].tag_len;
        scene_tags[k].action(content, i, id, data);
        *i += scene_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, true);
    }
}

void load_scene(char *path, scene_id id, game_data_t *data)
{
    char *content = load_file(path);
    int i = 1;

    skip_to_next_tag(content, &i, false);
    data->scenes->list[id].id = id;
    get_scene(content, &i, data ,id);
}