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

void free_multiple_ptr(int n, ...)
{
    va_list list;
    va_start(list, n);
    for (int i = 0; i < n; i++) {
        free(va_arg(list, void *));
    }
    va_end(list);
}

char *get_entity_path(xmlnode_t *node, char *scene_name)
{
    char *from = xml_value_str("from", node);
    char *scene1 = my_strcat("conf/scenes/", scene_name);
    char *scene2 = my_strcat(scene1, "/");
    char *scene3 = my_strcat(scene2, node->data);
    char *template = my_strcat("conf/entity_templates/", node->data);
    char *path = NULL;

    if (!from) {
        path = my_strndup(node->data, my_strlen(node->data));
        free_multiple_ptr(4, scene1, scene2, scene3, template);
        return path;
    } if (!my_strcmp(from, "scene")) {
        path = my_strcat(scene3, ".xml");
    } else if (!my_strcmp(from, "templates"))
        path = my_strcat(template, ".xml");
    free_multiple_ptr(4, scene1, scene2, scene3, template);
    return path;
}

int load_scene_entities(xmlnode_t *node, scene_array_t *scene)
{
    int count;
    entity_t *entity;

    if (!node)
        return 0;
    for (int i = 0; i < node->children.size; i ++) {
        count = xml_value_int("count", node->children.data[i]);
        if (!count)
            count++;
        for (int j = 0; j < count; j++) {
            entity = load_entity(
            get_entity_path(node->children.data[i], scene->name), NULL);
            add_entity(entity, &scene->objects->list);
        }
    }
}

int load_scene(char *path, scene_id id, game_data_t *data)
{
    char *path1 = my_strcat("conf/scenes/", path);
    char *path2 = my_strcat(path1, ".xml");
    xmldoc_t *doc = load_xmldoc(path2);
    xmlnode_t *node;

    if (!path1 || !path2 || !doc)
        return 0;
    node = doc->root;
    data->scenes->list[id].id = id;
    data->scenes->list[id].name = xml_value_str("name", node);
    data->scenes->list[id].toggle = xml_toggle("toggle", node);
    load_scene_entities(extract_xml_child("entities", node, false),
    &data->scenes->list[id]);
    free_xmlnode(doc->root);
    free_multiple_ptr(3, doc, path1, path2);
    return 1;
}