/*
** EPITECH PROJECT, 2020
** load_interactive_component.h
** File description:
** header for load_interactive_component.c
*/

#ifndef LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_H
#define LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void load_interact_toggle(char *content, int *i, interact_t *interact);
void load_interact_left_click(char *content, int *i, interact_t *interact);
void load_interact_right_click(char *content, int *i, interact_t *interact);

static const struct conf_tag_action_s interact_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_interact_toggle},
        {"<left_click>", 12, (void *(*)()) &load_interact_left_click},
        {"<right_click>", 13, (void *(*)()) &load_interact_right_click},
        {NULL, 0, NULL}

};

#endif //LIB_MYCSFML_LOAD_INTERACTIVE_COMPONENT_H
