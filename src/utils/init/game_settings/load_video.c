/*
** EPITECH PROJECT, 2020
** load_video.c
** File description:
** header for load_video.c
*/

#include "my_csfml.h"
#include "utils/init_xfml.h"
#include "my.h"

void set_window_title(char *content, int *i, game_data_t *data)
{
    data->game_settings->video->game_title = extract_value(content, i);
}

void set_window_height(char *content, int *i, game_data_t *data)
{
    char *value = extract_value(content, i);

    data->game_settings->video->height = my_getnbr(value);
    free(value);
}

void set_window_width(char *content, int *i, game_data_t *data)
{
    char *value = extract_value(content, i);

    data->game_settings->video->width = my_getnbr(value);
    free(value);
}

void set_max_fps(char *content, int *i, game_data_t *data)
{
    char *value = extract_value(content, i);

    data->game_settings->video->fps = my_getnbr(value);
    free(value);
}

void get_fullscreen_toggle(char *content, int *i, game_data_t *data)
{
    data->game_settings->video->is_fullscreen = fill_toogle(content, i);
}