/*
** EPITECH PROJECT, 2020
** load_transform_component.h
** File description:
** header for load_transform_component.c
*/

#ifndef LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H
#define LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void load_transform_toggle(char *content, int *i, transform_t *transform);
void load_transform_position(char *content, int *i, transform_t *transform);
void load_transform_scale(char *content, int *i, transform_t *transform);
void load_transform_velocity(char *content, int *i, transform_t *transform);
void load_transform_speed(char *content, int *i, transform_t *transform);

static struct conf_tag_action_s transform_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_transform_toggle},
        {"<position>", 10, (void *(*)()) &load_transform_position},
        {"<scale>", 7, (void *(*)()) &load_transform_scale},
        {"<velocity>", 10, (void *(*)()) &load_transform_velocity},
        {"<speed>", 7, (void *(*)()) &load_transform_speed},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_H
