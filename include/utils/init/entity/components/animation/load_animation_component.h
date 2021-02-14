/*
** EPITECH PROJECT, 2020
** load_animation_component.h
** File description:
** header for load_animation_component.c
*/

#ifndef LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H
#define LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H

#include "types.h"

void load_animation_toggle(char *content, int *i, animation_t *animation);
void load_animation_actual_frame(char *content, int *i, animation_t *animation);
void load_animation_anim_type(char *content, int *i, animation_t *animation);
void load_animation_actual_anim(char *content, int *i, animation_t *animation);
void load_anim_list(char *content, int *i, animation_t *animation);
void load_anim_toggle(char *content, int *i, anim_t *anim);
void load_anim_name(char *content, int *i, anim_t *anim);
void load_anim_frame_action(char *content, int *i, anim_t *anim);
void load_anim_frames(char *content, int *i, anim_t *anim);

#endif //LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H
