/*
** EPITECH PROJECT, 2020
** load_audio.c
** File description:
** header for load_audio.c
*/

#include "my_puterr.h"
#include "my.h"
#include "my_csfml.h"
#include "utils/init_xfml.h"

void set_music_volume(char *content, int *i, game_data_t *data)
{
    char *value = extract_value(content, i);

    data->game_settings->audio->music_volume = my_getnbr(value);
    free(value);
}

void set_sfx_volume(char *content, int *i, game_data_t *data)
{
    char *value = extract_value(content, i);

    data->game_settings->audio->sfx_volume = my_getnbr(value);
    free(value);
}

void get_music_count(char *content, int *i, game_data_t *data)
{
    char *value = extract_value(content, i);

    int count = my_getnbr(value);
    data->game_settings->audio->musics_count = count;
    data->game_settings->audio->musics = malloc_music_array(count);
    free(value);
}

void set_actual_theme(char *content, int *i, game_data_t *data)
{
    char *value = extract_value(content, i);

    data->game_settings->audio->actual_theme = my_getnbr(value);
    free(value);
}

void get_music_array(char *content, int *i, game_data_t *data)
{
    int j = 0;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</mlist>", 8)) {
        *i += 7;
        skip_to_next_tag(content, i, OPEN);
        *i += 6;
        data->game_settings->audio->musics[j].name = extract_value(content, i);
        *i += 7;
        skip_to_next_tag(content, i, NEXT);
        skip_to_next_tag(content, i, OPEN);
        *i += 6;
        data->game_settings->audio->musics[j].path = extract_value(content, i);
        *i += 7;
        skip_to_next_tag(content, i, NEXT);
        *i += 8;
        if (j + 1 == data->game_settings->audio->musics_count)
            skip_to_next_tag(content, i, CLOSE);
        else
            skip_to_next_tag(content, i, NEXT);
        j++;
    }
}