/*
** EPITECH PROJECT, 2020
** load_sounds_component_tabs.h
** File description:
** header for load_sounds_component_tabs.c
*/

#ifndef LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_TABS_H
#define LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "load_sounds_component.h"

static struct conf_tag_action_s sounds_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_sounds_toggle},
        {"<list count=\"", 13, (void *(*)()) &load_sounds_list},
        {NULL, 0, NULL}
};

static struct conf_tag_action_s sound_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_sound_toggle},
        {"<anim>", 6, (void *(*)()) &load_sound_anim},
        {"<name>", 6, (void *(*)()) &load_sound_name},
        {"<path>", 6, (void *(*)()) &load_sound_music},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_TABS_H
