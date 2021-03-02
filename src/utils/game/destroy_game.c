/*
** EPITECH PROJECT, 2020
** destroy_game.c
** File description:
** header for destroy_game.c
*/

#include <stdlib.h>
#include "../../../include/my_csfml.h"


void destroy_game_stats(game_stats_t *stats)
{
    sfClock_destroy(stats->time->game_clock);
    free(stats->time);
    sfView_destroy(stats->camera->camera);
    free(stats->camera->transform);
    free(stats->camera);
    free(stats->event);
    free(stats);
}

void destroy_game_settings(settings_t *settings)
{
    free_video_data(settings->video);
    free_audio_data(settings->audio);
    free(settings);
}

void destroy_game(game_data_t *data)
{
    destroy_game_stats(data->stats);
    destroy_game_scenes(data->scenes);
    free_entity_list(data->gui);
    free_entity_list(data->global_entity);
    free_entity_list(data->player);
    destroy_game_settings(data->game_settings);
    free(data);
}