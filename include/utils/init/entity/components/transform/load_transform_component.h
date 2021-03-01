/*
** EPITECH PROJECT, 2020
** load_transform_component.h
** File description:
** header for load_transform_component.c
*/

#ifndef LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H
#define LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H

#include "types.h"

int load_transform_toggle(xmlnode_t *node, transform_t *transform);
int load_transform_position(xmlnode_t *node, transform_t *transform);
int load_transform_scale(xmlnode_t *node, transform_t *transform);
int load_transform_speed(xmlnode_t *node, transform_t *transform);

#endif //LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H
