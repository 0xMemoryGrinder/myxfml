/*
** EPITECH PROJECT, 2020
** set_entity_properties.c
** File description:
** set_entity_properties.c
*/

#include "utils/init_xfml.h"
#include "my.h"
#include "my_puterr.h"

int load_entity_name(xmlnode_t *node, entity_t *entity)
{
    int status = 1;
    entity->name = xml_value_str("name", node, &status);

    if (!status || !entity->name)
        return *my_puterr("Error with entity name", __FILE__, __LINE__);
    return 1;
}

int load_entity_type(xmlnode_t *node, entity_t *entity)
{
    int status = 1;
    char *content = xml_value_str("type", node, &status);

    if (!status || !content)
        return *my_puterr("Error with entity type", __FILE__, __LINE__);
    entity->type = fill_enum(content, entity_type_enum_tab, &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

int load_entity_toggle(xmlnode_t *node, entity_t *entity)
{
    int status = 1;
    entity->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

static int load_entity_child(xmlnode_t *node, entity_t *entity)
{
    int status1 = 1;
    int status2 = 1;
    char *path = xml_value_str("path", node, &status1);
    entity_t *to_add = NULL;

    if (!status1)
        return 0;
    to_add = load_entity(path, entity);
    add_entity_children(to_add, &(entity->children));
    return 1;
}

int load_entity_children(xmlnode_t *node, entity_t *entity)
{
    int good = 1;

    for (int i = 0; i < node->children.size; i++) {
        good = load_entity_child(node->children.data[i], entity);
        if (!good)
            return 0;
    }
    return 1;
}