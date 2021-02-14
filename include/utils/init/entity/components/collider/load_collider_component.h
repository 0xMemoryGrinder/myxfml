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

void load_collider_toggle(char *content, int *i, collider_t *collider);
void load_collider_action(char *content, int *i, collider_t *collider);
void load_collider_position(char *content, int *i, collider_t *collider);
void load_collider_dimensions(char *content, int *i, collider_t *collider);

#endif //LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_H
