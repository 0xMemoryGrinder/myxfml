/*
** EPITECH PROJECT, 2020
** script_updates.h
** File description:
** header for script_updates.c
*/

#ifndef LIBCSFML_SCRIPT_UPDATES_H
#define LIBCSFML_SCRIPT_UPDATES_H

#include "../my_csfml.h"

void get_scripts_updates(game_data_t *data, entity_list_t *list);
void update_script(game_data_t *data, entity_list_t *entity, script_t *script);

#endif //LIBCSFML_SCRIPT_UPDATES_H
