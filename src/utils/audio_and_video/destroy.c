/*
** EPITECH PROJECT, 2020
** destroy.c
** File description:
** header for destroy.c
*/

#include <stdlib.h>
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/game.h"
#include "../../../include/types_and_base/video.h"
#include "../../../include/types_and_base/music.h"
#include "../../../include/types.h"
#include "my_puterr.h"

void free_video_data(video_data_t *video_data)
{
    free(video_data->game_title);
    sfRenderWindow_destroy(video_data->window);
    free(video_data);
}

void free_music_array(music_t *musics, int size)
{
    for (int i = 0; i < size; i++) {
        free(musics[i].name);
        sfMusic_destroy(musics[i].music);
    }
    free(musics);
}

void free_audio_data(audio_data_t *audio_data)
{
    free_music_array(audio_data->musics, audio_data->musics_count);
    free_sound_list(audio_data->sounds);
    free(audio_data);
}