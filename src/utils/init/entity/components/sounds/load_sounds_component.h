/*
** EPITECH PROJECT, 2020
** load_sounds_component.h
** File description:
** header for load_sounds_component.c
*/

#ifndef LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H
#define LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void load_sounds_list(char *content, int *i, sfx_list_t *sounds);
void set_sounds_toggle(char *content, int *i, sfx_list_t *sounds);

static struct conf_tag_action_s sounds_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &set_sounds_toggle},
        {"<list count=\"", 13, (void *(*)()) &load_sounds_list},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_SOUNDS_COMPONENT_H
