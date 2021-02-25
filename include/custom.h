/*
** EPITECH PROJECT, 2020
** custom.h
** File description:
** header for custom.c
*/

#ifndef MY_DEFENDER_CUSTOM_H
#define MY_DEFENDER_CUSTOM_H

#include "my_csfml.h"

// UPDATE SCRIPT FUNCTIONS
void *tower_attack_script(void **none, game_data_t *data, entity_list_t *);
void *hoover_rs_script(void **none, game_data_t *data, entity_list_t *entity);
void *mob_route_script(void **none, game_data_t *data, entity_list_t *mob);
void *walking_direction_script(void **, game_data_t *, entity_list_t *);
void *next_route(void **, game_data_t *, entity_list_t *);

// DESTROY DATA FUNCTIONS
void destroy_script_data(void **data);


// COLLIDERS ON COLLISION
void inject_next_route(entity_list_t *self, entity_list_t *collider,
game_data_t *data, sfIntRect intersect);

#endif //MY_DEFENDER_CUSTOM_H
