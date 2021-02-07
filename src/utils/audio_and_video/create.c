/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** header for create.c
*/

#include <stdlib.h>
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/game.h"
#include "../../../include/types_and_base/video.h"
#include "../../../include/types_and_base/music.h"
#include "../../../include/types.h"
#include "../my_puterr.h"

audio_data_t *malloc_audio_data(void)
{
    audio_data_t *new = malloc(sizeof(audio_data_t));

    if (new == NULL)
        my_puterr("Error malloc audio data", __FILE__, __LINE__);
    new->sounds = NULL;
    new->master_volume = 0;
    new->musics = NULL;
    new->musics_count = 0;
    return new;
}

video_data_t *malloc_video_data(void)
{
    video_data_t *new = malloc (sizeof(video_data_t));

    if (new == NULL)
        my_puterr("Error malloc video data", __FILE__, __LINE__);
    new->width = 0;
    new->height = 0;
    new->window = NULL;
    new->fps = 0;
    new->game_title = NULL;
    new->mode = (sfVideoMode){0, 0, 0};
    new->scale_factor = 1;
    return new;
}

music_t *malloc_music_array(int size)
{
    music_t *new = malloc(sizeof(music_t) * (size + 1));

    if (new == NULL)
        my_puterr("Error malloc music array", __FILE__, __LINE__);
    for (int i = 0; i < size; i++) {
        new[i].name = NULL;
        new[i].type = 0;
        new[i].music = NULL;
        new[i].volume = 0;
    }
    return new;
}