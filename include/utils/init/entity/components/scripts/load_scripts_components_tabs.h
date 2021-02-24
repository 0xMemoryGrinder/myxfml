/*
** EPITECH PROJECT, 2020
** load_scripts_components_tabs.h
** File description:
** header for load_scripts_components_tabs.c
*/

#ifndef LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_TABS_H
#define LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "load_scripts_components.h"

static struct conf_tag_action_s scripts_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_scripts_toggle},
        {"<list count=\"", 13, (void *(*)()) &load_scripts_list},
        {NULL, 0, NULL}
};

static struct conf_tag_action_s script_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_script_toggle},
        {"<name>", 6, (void *(*)()) &load_script_name},
        {"<time_dependent>", 16, (void *(*)()) &load_script_time_dep},
        {"<action>", 8, (void *(*)()) &load_script_action},
        {"<destroy>", 9, (void *(*)()) &load_script_destroy},
        {"<trigger>", 9, (void *(*)()) &load_script_trigger},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_TABS_H
