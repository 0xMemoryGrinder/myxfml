/*
** EPITECH PROJECT, 2020
** load_interactive_component.h
** File description:
** header for load_interactive_component.c
*/

#ifndef LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_H
#define LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_H

#include "types.h"

int load_interact_toggle(xmlnode_t *node, interact_t *interact);
int load_interact_left_click(xmlnode_t *node, interact_t *interact);
int load_interact_right_click(xmlnode_t *node, interact_t *interact);

#endif //LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_H
