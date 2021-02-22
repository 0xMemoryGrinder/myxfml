/*
** EPITECH PROJECT, 2020
** input_engine.h
** File description:
** header for input_engine.c
*/

#ifndef LIBCSFML_INPUT_ENGINE_H
#define LIBCSFML_INPUT_ENGINE_H

#include "../my_csfml.h"

void check_inputs(game_data_t *data, entity_list_t *interacts,
sfVector2i right, sfVector2i left);
void get_clicks_info(sfVector2i *right, sfVector2i *left, game_data_t *data);

#endif //LIBCSFML_INPUT_ENGINE_H
