/*
** EPITECH PROJECT, 2020
** load_scene.c
** File description:
** header for load_scene.c
*/

#include "my_xml.h"
#include "my_puterr.h"
#include "my_csfml.h"
#include "my.h"
#include "utils/init_xfml.h"
#include <stdarg.h>


char *get_entity_path(xmlnode_t *node, char *scene_name)
{
    int status = 1;
    char *from = xml_value_str("from", node, &status);
    char *scene = my_multiple_strcat(4,"conf/scenes/", scene_name, "/", node->data, ".xml");
    char *template = my_multiple_strcat(3, "conf/entity_templates/", node->data, ".xml");

    if (!from) {
        free_multiple_ptr(2, scene, template);
        if (status == 0)
            return NULL;
        return node->data;
    }
    if (!my_strcmp(from, "scene") && scene) {
        free_multiple_ptr(2, from, template);
        return scene;
    }
    if (!my_strcmp(from, "template") && template) {
        free_multiple_ptr(2, from, scene);
        return template;
    }
    return node->data;
}

int load_scene_entities(xmlnode_t *node, scene_array_t *scene)
{
    int count;
    entity_t *entity;

    if (!node)
        return -1;
    for (int i = 0; i < node->children.size; i ++) {
        count = xml_value_int("count", node->children.data[i], NULL);
        if (!count)
            count++;
        for (int j = 0; j < count; j++) {
            entity = load_entity(
            get_entity_path(node->children.data[i], scene->name), NULL);
            add_entity(entity, &scene->objects->list);
            if (!entity)
                return 0;
        }
    }
    return 1;
}

int scene_properties(xmlnode_t *node, scene_id id,
game_data_t *data, int *status)
{
    data->scenes->list[id].id = id;
    data->scenes->list[id].name = xml_value_str("name", node, status);
    data->scenes->list[id].toggle = xml_toggle("toggle", node, status);
    data->scenes->list[id].objects->background = load_entity( get_entity_path(
    extract_xml_child("background", node, false),
    data->scenes->list[id].name), NULL);
    if (!data->scenes->list[id].objects->background) {
        *status = 0;
        return 0;
    }
    return 1;
}

int load_scene(char *path, scene_id id, game_data_t *data)
{
    char *path1 = my_multiple_strcat(3 ,"conf/scenes/", path, "/.xml");
    xmldoc_t *doc = load_xmldoc(path1);
    xmlnode_t *node;
    int status = 1;

    if (!path1 || !doc)
        return 0;
    node = doc->root;
    scene_properties(node, id, data, &status);
    insert_globals(extract_xml_child("insert", node, false),
    data, &data->scenes->list[id]);
    if (!load_scene_entities(extract_xml_child("entities", node, false),
    &data->scenes->list[id]))
        return 0;
    free_xmlnode(doc->root);
    free_multiple_ptr(2, doc, path1);
    return status;
}