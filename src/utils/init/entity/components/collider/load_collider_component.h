/*
** EPITECH PROJECT, 2020
** load_collider_component.h
** File description:
** header for load_collider_component.c
*/

#ifndef LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_H
#define LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void load_collider_toggle(char *content, int *i, collider_t *collider);
void load_collider_action(char *content, int *i, collider_t *collider);
void load_collider_position(char *content, int *i, collider_t *collider);
void load_collider_dimensions(char *content, int *i, collider_t *collider);

static struct conf_tag_action_s collider_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_collider_toggle},
        {"<action>", 8, (void *(*)()) &load_collider_action},
        {"<position>", 10, (void *(*)()) &load_collider_position},
        {"<dimension>", 11, (void *(*)()) &load_collider_dimensions},
        {NULL, 0, NULL}
};


#endif //LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_H
