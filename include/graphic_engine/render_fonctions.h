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
void update_anim_frame(game_data_t *data, entity_t *list);
int get_animations_update(game_data_t *data, entity_list_t *animation);
void update_anim_state(entity_t * entity);


//
//  Render Sprites Updates
//
void get_render_updates(game_data_t *data, entity_list_t *renders);



//
//  Text Updates
//
void get_texts_updates(game_data_t *data, entity_list_t *texts);
void update_text(game_data_t *data, texts_t *texts, entity_t *entity);


//
//  Back Ground
//
void render_background(game_data_t *data, entity_t *background);

#endif //LIBCSFML_RENDER_FONCTIONS_H
