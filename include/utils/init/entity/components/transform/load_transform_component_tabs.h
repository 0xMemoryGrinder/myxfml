/*
** EPITECH PROJECT, 2020
** load_transform_component_tabs.h
** File description:
** header for load_transform_component_tabs.c
*/

#ifndef LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_TABS_H
#define LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "load_transform_component.h"

static struct conf_tag_action_s transform_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_transform_toggle},
        {"<position>", 10, (void *(*)()) &load_transform_position},
        {"<scale>", 7, (void *(*)()) &load_transform_scale},
        {"<velocity>", 10, (void *(*)()) &load_transform_velocity},
        {"<speed>", 7, (void *(*)()) &load_transform_speed},
        {"<rotation>", 10, (void *(*)()) &load_transform_rotation},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_TRANSFORM_COMPONENT_TABS_H
