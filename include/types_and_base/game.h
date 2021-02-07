/*
** EPITECH PROJECT, 2020
** game.h
** File description:
** header for game.c
*/

#ifndef LIBCSFML_GAME_H
#define LIBCSFML_GAME_H

#include "../my_csfml.h"

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

#endif //LIBCSFML_GAME_H
