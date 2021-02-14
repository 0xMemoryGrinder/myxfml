/*
** EPITECH PROJECT, 2020
** load_transform_component.h
** File description:
** header for load_transform_component.c
*/

#ifndef LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H
#define LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H

#include "types.h"

void load_transform_toggle(char *content, int *i, transform_t *transform);
void load_transform_position(char *content, int *i, transform_t *transform);
void load_transform_scale(char *content, int *i, transform_t *transform);
void load_transform_velocity(char *content, int *i, transform_t *transform);
void load_transform_speed(char *content, int *i, transform_t *transform);

#endif //LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H
