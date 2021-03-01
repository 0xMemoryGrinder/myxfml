/*
** EPITECH PROJECT, 2020
** load_collider_component.h
** File description:
** header for load_collider_component.c
*/

#ifndef LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_H
#define LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "types.h"

int load_collider_toggle(xmlnode_t *node, collider_t *collider);
int load_collider_action(xmlnode_t *node, collider_t *collider);
int load_collider_position(xmlnode_t *node, collider_t *collider);
int load_collider_dimensions(xmlnode_t *node, collider_t *collider);

#endif //LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_H
