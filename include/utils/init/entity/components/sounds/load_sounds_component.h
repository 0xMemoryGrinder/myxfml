/*
** EPITECH PROJECT, 2020
** load_sounds_component.h
** File description:
** header for load_sounds_component.c
*/

#ifndef LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H
#define LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H

#include "types.h"

void load_sounds_list(char *content, int *i, sfx_list_t *sounds);
void load_sounds_toggle(char *content, int *i, sfx_list_t *sounds);
void load_sound_toggle(char *content, int *i, sound_t *sound);
void load_sound_anim(char *content, int *i, sound_t *sound);
void load_sound_name(char *content, int *i, sound_t *sound);
void load_sound_music(char *content, int *i, sound_t *sound);

#endif //LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H
