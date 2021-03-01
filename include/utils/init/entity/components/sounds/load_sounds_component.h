/*
** EPITECH PROJECT, 2020
** load_sounds_component.h
** File description:
** header for load_sounds_component.c
*/

#ifndef LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H
#define LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H

#include "my_xml.h"
#include "types.h"

int load_sounds_list(xmlnode_t *node, sfx_list_t *sounds);
int load_sounds_toggle(xmlnode_t *node, sfx_list_t *sounds);
int load_sound_toggle(xmlnode_t *node, sound_t *sound);
int load_sound_anim(xmlnode_t *node, sound_t *sound);
int load_sound_name(xmlnode_t *node, sound_t *sound);
int load_sound_music(xmlnode_t *node, sound_t *sound);

#endif //LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H
