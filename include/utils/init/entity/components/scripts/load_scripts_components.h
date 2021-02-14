/*
** EPITECH PROJECT, 2020
** load_scripts_components.h
** File description:
** header for load_scripts_components.c
*/

#ifndef LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H
#define LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H

#include "types.h"

void load_scripts_list(char *content, int *i, script_list_t *scripts);
void load_scripts_toggle(char *content, int *i, script_list_t *scripts);
void load_script_toggle(char *content, int *i, script_t *script);
void load_script_time_dep(char *content, int *i, script_t *script);
void load_script_trigger(char *content, int *i, script_t *script);
void load_script_name(char *content, int *i, script_t *script);
void load_script_action(char *content, int *i, script_t *script);

#endif //LIB_MYCSFML_LOAD_SCRIPTS_COMPONENTS_H
