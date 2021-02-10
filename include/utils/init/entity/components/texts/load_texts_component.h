/*
** EPITECH PROJECT, 2020
** load_text_component.h
** File description:
** header for load_text_component.c
*/

#ifndef LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H
#define LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H

#include "../../../conf_tag_action_struct.h"
#include "../../../../../my_csfml.h"
#include <stdlib.h>

void set_texts_toggle(char *content, int *i, texts_t *texts);
void load_texts_list(char *content, int *i, texts_t *texts);

static struct conf_tag_action_s texts_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &set_texts_toggle},
        {"<list count=\"", 13, (void *(*)()) &load_texts_list},
        {NULL, 0, NULL}
};
#endif //LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H
