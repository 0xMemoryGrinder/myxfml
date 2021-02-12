/*
** EPITECH PROJECT, 2020
** load_texts_list.h
** File description:
** header for load_texts_list.c
*/

#ifndef LIB_MYCSFML_SET_TEXT_PROPERTIES_H
#define LIB_MYCSFML_SET_TEXT_PROPERTIES_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"

void set_text_id(char *content, int *i, text_t *text);
void set_text_toggle(char *content, int *i, text_t *text);
void set_text_font(char *content, int *i, text_t *text);
void set_text_position(char *content, int *i, text_t *text);
void set_text_offset(char *content, int *i, text_t *text);
void set_text_font_size(char *content, int *i, text_t *text);
void set_text_string(char *content, int *i, text_t *text);
void set_text_rs_linked(char *content, int *i, text_t *text);

static struct conf_tag_action_s text_conf_tag_action[] = {
        {"<id>", 4, (void *(*)()) &set_text_id},
        {"<toggle>", 8, (void *(*)()) &set_text_toggle},
        {"<rs_linked>", 11, (void *(*)()) &set_text_rs_linked},
        {"<path>", 6, (void *(*)()) &set_text_font},
        {"<position>", 10, (void *(*)()) &set_text_position},
        {"<offset>", 8, (void *(*)()) &set_text_offset},
        {"<font_size>", 11, (void *(*)()) &set_text_font_size},
        {"<string>", 8, (void *(*)()) &set_text_string},
        {NULL, 0, NULL}
        //{"components", 10, &load_components},
};

#endif //LIB_MYCSFML_SET_TEXT_PROPERTIES_H
