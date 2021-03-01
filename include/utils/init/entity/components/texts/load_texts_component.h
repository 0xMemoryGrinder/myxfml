/*
** EPITECH PROJECT, 2020
** load_text_component.h
** File description:
** header for load_text_component.c
*/

#ifndef LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H
#define LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H

#include "my_csfml.h"

int load_texts_toggle(xmlnode_t *node, texts_t *texts);
int load_texts_list(xmlnode_t *node, texts_t *texts);
int load_text_id(xmlnode_t *node, text_t *text);
int load_text_toggle(xmlnode_t *node, text_t *text);
int load_text_font(xmlnode_t *node, text_t *text);
int load_text_position(xmlnode_t *node, text_t *text);
int load_text_offset(xmlnode_t *node, text_t *text);
int load_text_font_size(xmlnode_t *node, text_t *text);
int load_text_string(xmlnode_t *node, text_t *text);
int load_text_rs_linked(xmlnode_t *node, text_t *text);

#endif //LIB_MYCSFML_LOAD_TEXTS_COMPONENT_H
