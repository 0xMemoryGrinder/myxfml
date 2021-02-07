/*
** EPITECH PROJECT, 2020
** render_fonctions.h
** File description:
** header for render_fonctions.c
*/

#ifndef LIBCSFML_RENDER_FONCTIONS_H
#define LIBCSFML_RENDER_FONCTIONS_H

#include "../types.h"


//
//  Animation Updaes
//
void update_anim_frame(game_data_t *data, entity_list_t *list);
void get_animations_update(game_data_t *data, entity_list_t *animation);



//
//  Render Sprites Updates
//
void get_render_updates(game_data_t *data, entity_list_t *renders);



//
//  Text Updates
//

#endif //LIBCSFML_RENDER_FONCTIONS_H
