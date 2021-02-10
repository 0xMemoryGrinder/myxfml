/*
** EPITECH PROJECT, 2020
** music.h
** File description:
** header for music.c
*/

#ifndef LIBCSFML_MUSIC_H
#define LIBCSFML_MUSIC_H

#include "../types.h"

struct music_s{
    char *name;
    char *path;
    sfMusic *music;
};


struct audio_data_s{
    int music_volume;
    int sfx_volume;
    int musics_count;
    int actual_theme;
    music_t *musics;
    sfx_list_t *sounds;
};


#endif //LIBCSFML_MUSIC_H
