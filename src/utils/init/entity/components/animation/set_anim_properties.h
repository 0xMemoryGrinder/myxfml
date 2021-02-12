/*
** EPITECH PROJECT, 2020
** set_anim_properties.h
** File description:
** header for set_anim_properties.c
*/

#ifndef LIB_MYCSFML_SET_ANIM_PROPERTIES_H
#define LIB_MYCSFML_SET_ANIM_PROPERTIES_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void load_anim_toggle(char *content, int *i, anim_t *anim);
void load_anim_name(char *content, int *i, anim_t *anim);
void load_anim_frame_count(char *content, int *i, anim_t *anim);
void load_anim_frame_action(char *content, int *i, anim_t *anim);
void set_anim_frames(char *content, int *i, anim_t *anim);

static struct conf_tag_action_s anim_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_anim_toggle},
        {"<name>", 6, (void *(*)()) &load_anim_name},
        {"<frame_action>", 14, (void *(*)()) &load_anim_frame_action},
        {"<frames count=\"", 15, (void *(*)()) &set_anim_frames},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_SET_ANIM_PROPERTIES_H
