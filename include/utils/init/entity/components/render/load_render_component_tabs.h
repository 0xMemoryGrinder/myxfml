/*
** EPITECH PROJECT, 2020
** load_render_component_tabs.h
** File description:
** header for load_render_component_tabs.c
*/

#ifndef LIB_MYCSFML_LOAD_RENDER_COMPONENT_TABS_H
#define LIB_MYCSFML_LOAD_RENDER_COMPONENT_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "load_render_component.h"

static struct conf_tag_action_s render_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_render_toggle},
        {"<path>", 6, (void *(*)()) &load_render_sprite},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_RENDER_COMPONENT_TABS_H
