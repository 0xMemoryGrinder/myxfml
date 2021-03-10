/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** header for create.c
*/

#include <stdlib.h>
#include "my_csfml.h"
#include "my_puterr.h"

audio_data_t *malloc_audio_data(void)
{
    audio_data_t *new = malloc(sizeof(audio_data_t));

    if (new == NULL)
        return (audio_data_t *)my_puterr("Error malloc audio data",
        __FILE__, __LINE__).ptr;
    new->sounds = NULL;
    new->sfx_volume = 0;
    new->music_volume = 0;
    new->musics = NULL;
    new->musics_count = 0;
    new->actual_theme = -1;
    return new;
}

camera_t *malloc_game_camera(void)
{
    camera_t *new = malloc(sizeof(camera_t));

    if (new == NULL)
        return (camera_t *)my_puterr("Error malloc game camera",
        __FILE__ ,__LINE__).ptr;
    new->transform = malloc(sizeof(transform_t));
    new->camera = sfView_create();
    if (new->transform == NULL || !new->camera)
        return (camera_t *)my_puterr("Error malloc camera / tranform",
        __FILE__, __LINE__).ptr;
    return new;
}

video_data_t *malloc_video_data(void)
{
    video_data_t *new = malloc (sizeof(video_data_t));

    if (new == NULL)
        return (video_data_t *)my_puterr("Error malloc video data",
        __FILE__, __LINE__).ptr;
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
    music_t *new = malloc(sizeof(music_t) * (size));

    if (new == NULL)
        return (music_t *)my_puterr("Error malloc music array",
        __FILE__, __LINE__).ptr;
    for (int i = 0; i < size; i++)
        new[i] = (music_t){.name = NULL, .path = NULL, .music = NULL};
    return new;
}