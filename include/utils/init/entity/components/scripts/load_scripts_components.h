/*
** EPITECH PROJECT, 2020
** load_scripts_components.h
** File description:
** header for load_scripts_components.c
*/

#ifndef LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H
#define LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H

#include "my_xml.h"
#include "types.h"

int load_scripts_list(xmlnode_t *node, script_list_t *scripts);
int load_scripts_toggle(xmlnode_t *node, script_list_t *scripts);
int load_script_toggle(xmlnode_t *node, script_t *script);
int load_script_time_dep(xmlnode_t *node, script_t *script);
int load_script_trigger(xmlnode_t *node, script_t *script);
int load_script_name(xmlnode_t *node, script_t *script);
int load_script_action(xmlnode_t *node, script_t *script);
int load_script_destroy(xmlnode_t *node, script_t *script);

#endif //LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H
