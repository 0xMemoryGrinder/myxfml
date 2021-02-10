/*
** EPITECH PROJECT, 2020
** audio_engine.h
** File description:
** header for audio_engine.c
*/

#ifndef LIBCSFML_AUDIO_ENGINE_H
#define LIBCSFML_AUDIO_ENGINE_H

#include "../my_csfml.h"

void sfx_engine(game_data_t *data, entity_list_t *list);
// UPDATING SFX
void sfx_array_updates(game_data_t *data, sfx_list_t *list);
void check_sound_state(game_data_t *data, sfx_list_t *list, int i);

//  updates global musics and sfx engine
void music_engine(game_data_t *data, audio_data_t *audio);

//  change actual theme by theme name
void change_theme(game_data_t *data, char *new_theme);

// check actual music (create and play it if not loaded)
void check_music_state(game_data_t *data, audio_data_t *audio, int actual);

#endif //LIBCSFML_AUDIO_ENGINE_H
