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
int tower_attack_script(void **none, game_data_t *data, entity_t *);
int hoover_rs_script(void **none, game_data_t *data, entity_t *entity);
int mob_route_script(void **none, game_data_t *data, entity_t *mob);
int walking_direction_script(void **, game_data_t *, entity_t *);
int next_route(void **, game_data_t *, entity_t *);
int health_stats_script(void **none, game_data_t *data,
entity_t *entity);
int attack_stats_script(void **none, game_data_t *data,
entity_t *entity);
int wave_control_script(void **none, game_data_t *data,
entity_t *unused);
int on_sign_click(void **none, game_data_t *data, entity_t *entity);
int set_buildmenu_script(void **unused, game_data_t *data, entity_t *entity);


// DESTROY DATA FUNCTIONS
void destroy_script_data(void **data);


// COLLIDERS ON COLLISION
int inject_next_route(entity_t *self, entity_t *collider,
game_data_t *data);

#endif //MY_DEFENDER_CUSTOM_H
