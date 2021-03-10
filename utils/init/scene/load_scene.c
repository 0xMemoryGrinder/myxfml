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
#include "utils/init/entity/components/scripts/load_scripts_components.h"

int load_scene_scripts(xmlnode_t *node, scene_array_t *scene)
{
    if (!node)
        return -1;
    scene->scene_scripts = malloc_script_list();

    if (scene->scene_scripts == NULL ||
        !load_scripts_toggle(node, scene->scene_scripts) ||
        !load_scripts_list(node, scene->scene_scripts))
        return 0;
    return 1;
}

char *get_entity_path(xmlnode_t *node, char *scene_name)
{
    int status = 1;
    char *from = xml_value_str("from", node, &status);
    char *scene = my_multiple_strcat(5,"conf/scenes/", scene_name, "/", node->data, ".xml");
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
    } if (!my_strcmp(from, "template") && template) {
        free_multiple_ptr(2, from, scene);
        return template;
    } my_puterr("Error with \"from\" attribute in scene conf",
    __FILE__, __LINE__);
    return node->data;
}

int load_scene_entities(xmlnode_t *node, scene_array_t *scene)
{
    entity_t *entity;
    int status = 1;
    int status2 = 1;
    char *path;

    if (!node)
        return -1;
    for (int i = 0; i < node->children.size; i ++) {
        path = get_entity_path(node->children.data[i], scene->name);
        entity = load_entity(path, NULL);
        free(path);
        if (! entity)
            return 0;
        if (xml_toggle("modify", node->children.data[i], &status) == 1
        && status)
            status2 = moddify_entity(node->children.data[i], entity);
        if (! status || ! status2)
            return 0;
        add_entity(entity, &scene->objects->list);
    } return 1;
}

int scene_properties(xmlnode_t *node, scene_id id,
game_data_t *data, int *status)
{
    char *path = NULL;

    data->scenes->list[id].id = id;
    data->scenes->list[id].name = xml_value_str("name", node, status);
    path =  get_entity_path(
    extract_xml_child("background", node, false), data->scenes->list[id].name);
    data->scenes->list[id].toggle = xml_toggle("toggle", node, status);
    data->scenes->list[id].objects->background = load_entity(path, NULL);
    free(path);
    if (!data->scenes->list[id].objects->background)
        *status = 0;
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
    load_scene_scripts(extract_xml_child("scripts", node, false),
    &G_ACTUAL_SCENE);
    insert_globals(extract_xml_child("insert", node, false),
    data, &data->scenes->list[id]);
    if (!status || !load_scene_entities(extract_xml_child("entities",
    node, false), &data->scenes->list[id]))
        return 0;
    free_xmlnode(doc->root);
    free_multiple_ptr(2, doc, path1);
    return status;
}

/*
 * <entity count="1" from="scene">routes/route_1</entity>
<entity count="1" from="scene">routes/route_2</entity>
<entity count="1" from="scene">routes/route_3</entity>
<entity count="1" from="scene">routes/route_4</entity>
<entity count="1" from="scene">routes/route_5</entity>
<entity count="1" from="scene">routes/route_6</entity>
 */