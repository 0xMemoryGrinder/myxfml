/*
** EPITECH PROJECT, 2020
** load_render_component.h
** File description:
** header for load_render_component.c
*/

#ifndef LIB_MYCSFML_LOAD_RENDER_COMPONENT_H
#define LIB_MYCSFML_LOAD_RENDER_COMPONENT_H

#include "types.h"

int load_render_toggle(xmlnode_t *node, render_sprite_t *render);
int load_render_sprite(xmlnode_t *node, render_sprite_t *render);

#endif //LIB_MYCSFML_LOAD_RENDER_COMPONENT_H
