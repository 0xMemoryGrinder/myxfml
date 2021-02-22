/*
** EPITECH PROJECT, 2020
** load_interactive_component_tabs.h
** File description:
** header for load_interactive_component_tabs.c
*/

#ifndef LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_TABS_H
#define LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "load_interactive_component.h"

static const struct conf_tag_action_s interact_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_interact_toggle},
        {"<left_click>", 12, (void *(*)()) &load_interact_left_click},
        {"<right_click>", 13, (void *(*)()) &load_interact_right_click},
        {NULL, 0, NULL}

};

#endif //LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_TABS_H
