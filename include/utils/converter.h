/*
** EPITECH PROJECT, 2020
** converter.h
** File description:
** header for converter.c
*/

#ifndef LIBCSFML_CONVERTER_H
#define LIBCSFML_CONVERTER_H

#include "types.h"

sfIntRect get_rect(sfVector2f pos, sfVector2f dim, sfVector2f);
void get_sprite_collider(entity_t *entity, float x, float y);
#endif //LIBCSFML_CONVERTER_H
