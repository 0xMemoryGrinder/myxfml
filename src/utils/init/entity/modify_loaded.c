/*
** EPITECH PROJECT, 2020
** modify_loaded.c
** File description:
** header for modify_loaded.c
*/

#include "my_csfml.h"
#include "my_xml.h"

int mod_float_value(xmlnode_t *node, float *data, char *key)
{
    int status = 1;
    int value = xml_value_int(key, node, &status);

    if (!data)
        return status;
    if (status -= -1)
        *data = (float)value;
    return status;
}

int mod_int_value(xmlnode_t *node, int *data, char *key)
{
    int status = 1;
    int value = xml_value_int(key, node, &status);

    if (!data)
        return status;
    if (status -= -1)
        *data = value;
    return status;
}

int mod_toggle(xmlnode_t *node, toggle_t *toggle, char *key)
{
    int status = 1;
    int value = xml_toggle(key, node, &status);

    if (!toggle)
        return status;
    if (value != -1 && status != 0)
        *toggle = value;
    return status;
}

static int modify_transform(xmlnode_t *node, entity_t *entity)
{
    if (!E_TRANSFORM)
        return -1;
    mod_toggle(node, &E_TRANSFORM->toggle, "trans-toggle");
    mod_float_value(node, &E_TRANSFORM->position.x, "trans-x");
    mod_float_value(node, &E_TRANSFORM->position.y, "trans-y");
    return 1;
}

static int modify_collider(xmlnode_t *node, entity_t *entity)
{
    if (!E_COLLIDER)
        return -1;
    mod_toggle(node, &E_COLLIDER->toggle, "coll-toggle");
    mod_float_value(node, &E_COLLIDER->position.x, "coll-x");
    mod_float_value(node, &E_COLLIDER->position.y, "coll-y");
    mod_float_value(node, &E_COLLIDER->dimensions.x, "coll-w");
    mod_float_value(node, &E_COLLIDER->dimensions.y, "coll-h");
    return 1;
}

static int modify_scripts(xmlnode_t *node, entity_t *entity)
{

}

int moddify_entity(xmlnode_t *node, entity_t *entity)
{
    mod_toggle(node, &entity->toggle, "entity-toggle");

}