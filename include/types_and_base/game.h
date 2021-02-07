/*
** EPITECH PROJECT, 2020
** game.h
** File description:
** header for game.c
*/

#ifndef LIBCSFML_GAME_H
#define LIBCSFML_GAME_H

#include "../types.h"

//
//  Camera info
//
struct camera_s{
    sfView *camera;
    sfFloatRect transform;
    int insight_count;
    entity_t *insight_object;
};


//
// Data Definitions
//

struct time_stats_s{
    sfClock *game_clock;
    sfInt32 time;
};

struct game_stats_s{
    time_stats_t *time;
    sfEvent *event;
    camera_t *camera;
};

struct settings_s{
    video_data_t *video;
    audio_data_t *audio;
};

struct game_data_s{
    entity_t *global_entity;
    entity_t *gui;
    entity_t *player;
    scenes_t *scenes;
    game_stats_t *stats;
    settings_t *game_settings;
};



//
//  Create game data
//
audio_data_t *malloc_audio_data(void);
video_data_t *malloc_video_data(void);
music_t *malloc_music_array(int size);
game_data_t *malloc_game_data(void);
game_stats_t *malloc_game_stats(void);
settings_t *malloc_settings(void);



//
//  Destroy game data
//
void free_video_data(video_data_t *video_data);
void free_audio_data(audio_data_t *audio_data);
void destroy_game_settings(settings_t *settings);
void destroy_game_stats(game_stats_t *stats);
void destroy_game(game_data_t *data);

#endif //LIBCSFML_GAME_H
