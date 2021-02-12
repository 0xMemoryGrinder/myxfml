/*
** EPITECH PROJECT, 2020
** create_audio.c
** File description:
** header for create_audio.c
*/

#include "my_puterr.h"
#include "my.h"
#include "my_csfml.h"
#include "utils/init_xfml.h"


game_data_t *malloc_game(void)
{
    game_data_t *data = malloc_game_data();

    data->stats = malloc_game_stats();
    data->stats->time = malloc_time_stats();
    data->stats->camera = malloc_game_camera();
    data->scenes = malloc_scene_struct();
    data->game_settings = malloc_settings();
    data->game_settings->audio = malloc_audio_data();
    data->game_settings->video = malloc_video_data();
    return data;
}