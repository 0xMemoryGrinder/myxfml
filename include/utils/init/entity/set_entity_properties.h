/*
** EPITECH PROJECT, 2020
** set_entity_properties.h
** File description:
** header for set_entity_properties.c
*/

#ifndef LIB_MYCSFML_SET_ENTITY_PROPERTIES_H
#define LIB_MYCSFML_SET_ENTITY_PROPERTIES_H

#include "../../../my_csfml.h"

void set_entity_name(char *content, int *i, entity_t *entity);
void set_entity_type(char *content, int *i, entity_t *entity);
void set_entity_toggle(char *content, int *i, entity_t *entity);

#endif //LIB_MYCSFML_SET_ENTITY_PROPERTIES_H
