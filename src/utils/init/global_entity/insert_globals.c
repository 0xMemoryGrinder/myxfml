/*
** EPITECH PROJECT, 2020
** insert_globals.c
** File description:
** header for insert_globals.c
*/

#include "my_csfml.h"
#include "my.h"
#include "utils/init_xfml.h"
#include "my_puterr.h"
#include "my_xml.h"

int insert_gui(xmlnode_t *node, game_data_t *data ,scene_array_t *scene)
{
    entity_t *entity;
    xmlnode_list_t list;

    if (!node)
        return -1;
    list = node->children;
    if (xml_toggle("all", node)) {
        for (entity = data->gui; entity ; entity = entity->next) {
            add_entity(entity, &scene->objects->list);
        }
        return 1;
    }
    for (int i = 0; i < list.size; i++) {
        entity = get_entity_name(data->gui, list.data[i]->data);
        if (!entity)
        add_entity(entity, &scene->objects->list);
    }
    return 1;
}

int insert_player(xmlnode_t *node, game_data_t *data ,scene_array_t *scene)
{
    entity_t *entity;
    xmlnode_list_t list;

    if (!node)
        return -1;
    list = node->children;
    if (xml_toggle("all", node)) {
        for (entity = data->player; entity ; entity = entity->next) {
            add_entity(entity, &scene->objects->list);
        }
        return 1;
    }
    for (int i = 0; i < list.size; i++) {
        entity = get_entity_name(data->player, list.data[i]->data);
        if (!entity)
            add_entity(entity, &scene->objects->list);
    }
    return 1;
}

int insert_global(xmlnode_t *node, game_data_t *data ,scene_array_t *scene)
{
    entity_t *entity;
    xmlnode_list_t list;

    if (!node)
        return -1;
    list = node->children;
    if (xml_toggle("all", node)) {
        for (entity = data->global_entity; entity ; entity = entity->next) {
            add_entity(entity, &scene->objects->list);
        }
        return 1;
    }
    for (int i = 0; i < list.size; i++) {
        entity = get_entity_name(data->global_entity, list.data[i]->data);
        if (!entity)
            add_entity(entity, &scene->objects->list);
    }
    return 1;
}


int insert_globals(xmlnode_t *node, game_data_t *data, scene_array_t *scene)
{
    if (!node)
        return -1;
    insert_gui(extract_xml_child("gui", node, false), data, scene);
    insert_player(extract_xml_child("player", node, false), data, scene);
    insert_global(extract_xml_child("globals", node, false), data, scene);
    return 1;
}