/*
** EPITECH PROJECT, 2020
** collision.h
** File description:
** header for collision.c
*/

#ifndef LIBCSFML_PHYSICS_H
#define LIBCSFML_PHYSICS_H

#include "../types.h"

int physics_update(entity_list_t *list, game_data_t *data);
int check_collision(entity_list_t *entity, entity_list_t *collider,
                     game_data_t *data);


void transform_rendersprite(entity_t *entity);
void transform_collider(entity_t *entity);
void reset_transform(entity_t *entity);
void transform_updates(game_data_t *data, entity_list_t *transforms);

float get_direction(sfVector2f position, float speed, sfVector2f target, sfVector2f *new);

#endif //LIBCSFML_PHYSICS_H
