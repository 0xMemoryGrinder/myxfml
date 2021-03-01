/*
** EPITECH PROJECT, 2020
** load_animation_tab.h
** File description:
** header for load_animation_tab.c
*/

#ifndef LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_TABS_H
#define LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"

static struct conf_tag_action_s animation_conf_tag_action[] = {
        {"toggle", 8, (void *(*)()) &load_animation_toggle},
        {"actual_frame", 14, (void *(*)()) &load_animation_actual_frame},
        {"anim_type>", 11, (void *(*)()) &load_animation_anim_type},
        {"actual_anim>", 13, (void *(*)()) &load_animation_actual_anim},
        {NULL, 0, NULL}
};

static struct conf_tag_action_s anim_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_anim_toggle},
        {"<name>", 6, (void *(*)()) &load_anim_name},
        {"<frame_action>", 14, (void *(*)()) &load_anim_frame_action},
        {"<frames count=\"", 15, (void *(*)()) &load_anim_frames},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_ANIMATION_COMPONENT_TABS_H
