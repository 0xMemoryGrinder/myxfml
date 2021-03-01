/*
** EPITECH PROJECT, 2020
** load_animation_component.h
** File description:
** header for load_animation_component.c
*/

#ifndef LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H
#define LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H

#include "types.h"
#include "my_xml.h"

int load_animation_toggle(xmlnode_t *node, animation_t *animation);
int load_animation_actual_frame(xmlnode_t *node, animation_t *animation);
int load_animation_anim_type(xmlnode_t *node, animation_t *animation);
int load_animation_actual_anim(xmlnode_t *node, animation_t *animation);
int load_anim_list(xmlnode_t *node, animation_t *animation);
int load_anim_toggle(xmlnode_t *node, anim_t *anim);
int load_anim_name(xmlnode_t *node, anim_t *anim);
int load_anim_frame_action(xmlnode_t *node, anim_t *anim);
int load_anim_frames(xmlnode_t *node, anim_t *anim);

#endif //LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H
