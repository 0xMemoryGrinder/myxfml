/*
** EPITECH PROJECT, 2020
** load_animation_component.h
** File description:
** header for load_animation_component.c
*/

#ifndef LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H
#define LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void set_animation_toggle(char *content, int *i, animation_t *animation);
void set_animation_actual_frame(char *content, int *i, animation_t *animation);
void set_animation_anim_type(char *content, int *i, animation_t *animation);
void set_animation_actual_anim(char *content, int *i, animation_t *animation);
void load_anim_list(char *content, int *i, animation_t *animation);

static struct conf_tag_action_s animation_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &set_animation_toggle},
        {"<actual_frame>", 14, (void *(*)()) &set_animation_actual_frame},
        {"<anim_type>", 11, (void *(*)()) &set_animation_anim_type},
        {"<actual_anim>", 13, (void *(*)()) &set_animation_actual_anim},
        {"<list count=\"", 13, (void *(*)()) &load_anim_list},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_H
