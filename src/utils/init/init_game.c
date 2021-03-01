/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** header for init_game.c
*/

#include "../../../include/my_csfml.h"
#include "../../../include/utils/init_xfml.h"
#include "../../../include/my.h"
#include "my_puterr.h"
#include "my_xml.h"

#define GAME_CONF "conf/game_cfg.xml"

game_data_t *malloc_game(void);

int load_camera(xmlnode_t *node, game_data_t *data)
{
    if (!node)
        return -1;
    G_CAMERA->transform->scale.x = xml_value_float("x", node);
    G_CAMERA->transform->scale.y = xml_value_float("y", node);
    if (G_CAMERA->transform->scale.y && G_CAMERA->transform->scale.x)
        sfView_setSize(G_VIEW ,G_CAMERA->transform->scale);
    return 1;
}

int load_game_scenes(xmlnode_t *node, game_data_t *data)
{
    if (!node)
        return -1;
    data->scenes->count = xml_value_int("count", node);
    data->scenes->actual = xml_value_int("actual", node);
    data->scenes->list = malloc_scene_array(data->scenes->count);
    if (data->scenes->list)
        return 0;
    for (int i = 0; i < data->scenes->count; i++) {
        if (!load_scene(node->children.data[i]->data, i, data))
            return 0;
    }
    return 1;
}

int load_video(xmlnode_t *node, game_data_t *data)
{
    if (!node)
        return -1;
    data->game_settings->video->width = xml_value_int("x", node);
    data->game_settings->video->height = xml_value_int("y", node);
    data->game_settings->video->game_title = xml_value_str("fullscreen", node);
    data->game_settings->video->fps = xml_value_int("fps", node);
    data->game_settings->video->is_fullscreen = xml_toggle("fullscreen", node);
    return 1;
}

int load_game_conf(char *path, game_data_t *data)
{
    xmldoc_t *doc = load_xmldoc(path);
    xmlnode_t *node;
    int status = 1;

    if (doc == NULL)
        return 0;
    node = doc->root;
    load_camera(extract_xml_child("camera", node, false), data);
    if (!load_game_scenes(extract_xml_child("scenes", node, false), data))
        return 0;
    load_video(extract_xml_child("video", node, false), data);
    return 1;
}

game_data_t *create_game(void)
{
    game_data_t *data = malloc_game();

    if (!load_game_conf(GAME_CONF, data))
        return NULL;
    data->game_settings->video->mode.width = data->game_settings->video->width;
    data->game_settings->video->mode.height =
    data->game_settings->video->height;
    data->game_settings->video->mode.bitsPerPixel = 32;
    data->stats->event = malloc(sizeof(sfEvent));
    if (data->stats->event == NULL)
        return NULL;
    return data;
}