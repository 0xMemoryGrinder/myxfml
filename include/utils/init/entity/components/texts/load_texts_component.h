/*
** EPITECH PROJECT, 2020
** load_text_component.h
** File description:
** header for load_text_component.c
*/

#ifndef LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H
#define LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H

#include "my_csfml.h"

void load_texts_toggle(char *content, int *i, texts_t *texts);
void load_texts_list(char *content, int *i, texts_t *texts);
void load_text_id(char *content, int *i, text_t *text);
void load_text_toggle(char *content, int *i, text_t *text);
void load_text_font(char *content, int *i, text_t *text);
void load_text_position(char *content, int *i, text_t *text);
void load_text_offset(char *content, int *i, text_t *text);
void load_text_font_size(char *content, int *i, text_t *text);
void load_text_string(char *content, int *i, text_t *text);
void load_text_rs_linked(char *content, int *i, text_t *text);

#endif //LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H
