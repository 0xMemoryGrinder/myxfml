/*
** EPITECH PROJECT, 2020
** game.h
** File description:
** header for game.c
*/

#ifndef LIBCSFML_GAME_H
#define LIBCSFML_GAME_H

#include "my_csfml.h"

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
};

struct global_stats_s {
    char *actual_scene;
    int mile_stones;
    text_t *total_time;
    text_t *progression;
    text_t *difficulty;
    int diff_mult;
};

struct game_stats_s{
    time_stats_t *time;
    global_stats_t *global;
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
    scene_t *scene;
    game_stats_t *stats;
    settings_t *game_settings;
};

#endif //LIBCSFML_GAME_H
