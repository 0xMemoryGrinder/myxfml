/*
** EPITECH PROJECT, 2020
** load_scripts_components.h
** File description:
** header for load_scripts_components.c
*/

#ifndef LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H
#define LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void load_scripts_list(char *content, int *i, script_list_t *scripts);
void set_scripts_toggle(char *content, int *i, script_list_t *scripts);

static struct conf_tag_action_s scripts_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &set_scripts_toggle},
        {"<list count=\"", 13, (void *(*)()) &load_scripts_list},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H
