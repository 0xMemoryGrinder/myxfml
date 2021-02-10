/*
** EPITECH PROJECT, 2020
** set_script_property.h
** File description:
** header for set_script_property.c
*/

#ifndef LIB_MYCSFML_SET_SCRIPT_PROPERTIES_H
#define LIB_MYCSFML_SET_SCRIPT_PROPERTIES_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void set_script_toggle(char *content, int *i, script_t *script);
void set_script_time_dep(char *content, int *i, script_t *script);
void set_script_trigger(char *content, int *i, script_t *script);
void set_script_name(char *content, int *i, script_t *script);
void set_script_action(char *content, int *i, script_t *script);

static struct conf_tag_action_s script_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &set_script_toggle},
        {"<name>", 6, (void *(*)()) &set_script_name},
        {"<time_dependent>", 16, (void *(*)()) &set_script_time_dep},
        {"<action>", 8, (void *(*)()) &set_script_action},
        {"<trigger>", 9, (void *(*)()) &set_script_trigger},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_SET_SCRIPT_PROPERTIES_H
