/*
** EPITECH PROJECT, 2020
** collision.h
** File description:
** header for collision.c
*/

#ifndef LIBCSFML_COLLISION_H
#define LIBCSFML_COLLISION_H

#include "../types.h"

void physics_update(entity_list_t *list, game_data_t *data);
void check_collision(entity_list_t *entity, entity_list_t *collider,
                     game_data_t *data);

#endif //LIBCSFML_COLLISION_H
