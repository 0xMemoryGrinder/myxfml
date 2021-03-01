/*
** EPITECH PROJECT, 2020
** load_transform_component.c
** File description:
** load_transform_component.c
*/

#include "my_xml.h"
#include "my_csfml.h"
#include "utils/init/load_file.h"
#include "my.h"
#include "my_puterr.h"

int load_transform_position(xmlnode_t *node, transform_t *transform)
{
    int status1 = 1;
    int status2 = 1;
    transform->position.x = (float)xml_value_int("xpos", node, &status1);
    transform->position.y = (float)xml_value_int("ypos", node, &status2);

    if (!status1 || !status2)
        return 0;
    return 1;
}

int load_transform_scale(xmlnode_t *node, transform_t *transform)
{
    int status1 = 1;
    int status2 = 1;
    transform->scale.x = xml_value_float("xscale", node, &status1);
    transform->scale.y = xml_value_float("yscale", node, &status2);

    if (!status1 || !status2)
        return 0;
    return 1;
}

int load_transform_speed(xmlnode_t *node, transform_t *transform)
{
    int status = 1;
    transform->speed = xml_value_float("speed", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_transform_toggle(xmlnode_t *node, transform_t *transform)
{
    int status = 1;
    transform->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_transform_component(xmlnode_t *node, components_t *components)
{
    components->transform = malloc_transform();

    if (components->transform == NULL ||
    !load_transform_toggle(node, components->transform) ||
    !load_transform_position(node, components->transform) ||
    !load_transform_scale(node, components->transform) ||
    !load_transform_speed(node, components->transform))
        return 0;
    return 1;
}