/*
** EPITECH PROJECT, 2020
** input_engine.h
** File description:
** header for input_engine.c
*/

#ifndef LIBCSFML_INPUT_ENGINE_H
#define LIBCSFML_INPUT_ENGINE_H

#include "../my_csfml.h"

sfVector2f get_cursor_pos(game_data_t *data);
void check_inputs(game_data_t *data, entity_list_t *interacts,
sfVector2f right, sfVector2f left);
void get_clicks_info(sfVector2f *right, sfVector2f *left, game_data_t *data);

#endif //LIBCSFML_INPUT_ENGINE_H
