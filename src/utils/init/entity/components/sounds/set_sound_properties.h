/*
** EPITECH PROJECT, 2020
** set_sound_properties.h
** File description:
** header for set_sound_properties.c
*/

#ifndef LIB_MYCSFML_SET_SOUND_PROPERTIES_H
#define LIB_MYCSFML_SET_SOUND_PROPERTIES_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void set_sound_toggle(char *content, int *i, sound_t *sound);
void set_sound_anim(char *content, int *i, sound_t *sound);
void set_sound_name(char *content, int *i, sound_t *sound);
void set_sound_music(char *content, int *i, sound_t *sound);

static struct conf_tag_action_s sound_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &set_sound_toggle},
        {"<anim>", 6, (void *(*)()) &set_sound_anim},
        {"<name>", 6, (void *(*)()) &set_sound_name},
        {"<path>", 6, (void *(*)()) &set_sound_music},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_SET_SOUND_PROPERTIES_H
