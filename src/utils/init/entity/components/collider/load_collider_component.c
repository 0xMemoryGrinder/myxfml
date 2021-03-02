/*
** EPITECH PROJECT, 2020
** load_collider_component.c
** File description:
** load_collider_component.c
*/

#include <stdlib.h>
#include "my_xml.h"
#include "my_csfml.h"
#include "my.h"
#include "utils/init/common_tags.h"

int load_collider_toggle(xmlnode_t *node, collider_t *collider)
{
    int status = 1;
    collider->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_collider_position(xmlnode_t *node, collider_t *collider)
{
    int status1 = 1;
    int status2 = 1;
    collider->position.x = (float)xml_value_int("xpos", node, &status1);
    collider->position.y = (float)xml_value_int("ypos", node, &status2);

    if (!status1 || !status2)
        return 0;
    return 1;
}

int load_collider_dimensions(xmlnode_t *node, collider_t *collider)
{
    int status1 = 1;
    int status2 = 1;
    collider->dimensions.x = (float)xml_value_int("xdimension", node,
    &status1);
    collider->dimensions.y = (float)xml_value_int("ydimension", node,
    &status2);

    if (!status1 || !status2)
        return 0;
    return 1;
}

int load_collider_action(xmlnode_t *node, collider_t *collider)
{
    int status = 1;
    char *content = xml_value_str("action", node, &status);

    if (!status)
        return 0;
    if (!content)
        return 1;
    collider->on_collison = (void (*)(entity_list_t *, entity_list_t *,
    game_data_t *, sfIntRect)) fill_function(content, collider_func_ptr_tab,
    &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

int load_collider_component(xmlnode_t *node, components_t *components)
{
    components->collider = malloc_collider();


    if (components->collider == NULL ||
    !load_collider_toggle(node, components->collider) ||
    !load_collider_position(node, components->collider) ||
    !load_collider_dimensions(node, components->collider) ||
    !load_collider_action(node, components->collider))
        return 0;
    return 1;
}