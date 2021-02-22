/*
** EPITECH PROJECT, 2020
** load_collider_component_tabs.h
** File description:
** header for load_collider_component_tabs.c
*/

#ifndef LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_TABS_H
#define LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "load_collider_component.h"

static struct conf_tag_action_s collider_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_collider_toggle},
        {"<action>", 8, (void *(*)()) &load_collider_action},
        {"<position>", 10, (void *(*)()) &load_collider_position},
        {"<dimensions>", 11, (void *(*)()) &load_collider_dimensions},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_COLLIDER_COMPONENT_TABS_H
