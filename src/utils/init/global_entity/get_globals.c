/*
** EPITECH PROJECT, 2020
** get_globals.c
** File description:
** header for get_globals.c
*/

#include "my_csfml.h"
#include "utils/init_xfml.h"
#include "my.h"

#define GLOBAL_PATH "conf/global_entities/"
#define PLAYER_PATH "conf/player/"
#define GUI_PATH "conf/gui/"
#define XML ".xml"

//
//  Game Globals
//


int load_player(xmlnode_t *node, game_data_t *data)
{
    char *path;
    xmlnode_list_t list;
    entity_t *entity = NULL;

    if (!node)
        return -1;
    list = node->children;
    data->player = malloc_entity_node();
    if (!data->player)
        return 0;
    for (int i = 0; i < node->children.size; i++) {
        path = get_entity_path(list.data[i], NULL);
        if (!path)
            return 0;
        entity = load_entity(path, NULL);
        if (entity)
            add_entity(entity, &data->player);
    }
    return 1;
}

int load_gui(xmlnode_t *node, game_data_t *data)
{
    char *path;
    xmlnode_list_t list;
    entity_t *entity = NULL;

    if (!node)
        return -1;
    list = node->children;
    data->gui = malloc_entity_node();
    if (!data->gui)
        return 0;
    for (int i = 0; i < node->children.size; i++) {
        path = get_entity_path(list.data[i], NULL);
        if (!path)
            return 0;
        entity = load_entity(path, NULL);
        if (entity)
            add_entity(entity, &data->gui);
    }
    return 1;
}

int load_globals(xmlnode_t *node, game_data_t *data)
{
    char *path;
    xmlnode_list_t list;
    entity_t *entity = NULL;

    if (!node)
        return -1;
    list = node->children;
    data->global_entity = malloc_entity_node();
    if (!data->global_entity)
        return 0;
    for (int i = 0; i < node->children.size; i++) {
        path = get_entity_path(list.data[i], NULL);
        if (!path)
            return 0;
        entity = load_entity(path, NULL);
        if (entity)
            add_entity(entity, &data->global_entity);
    }
    return 1;
}

int load_global_entities(xmlnode_t *node, game_data_t *data)
{
    if (!node)
        return -1;
    if (!load_player(extract_xml_child("player", node, false), data) ||
    !load_globals(extract_xml_child("globals", node, false), data) ||
    !load_gui(extract_xml_child("gui", node, false), data))
        return 0;
    return 1;
}