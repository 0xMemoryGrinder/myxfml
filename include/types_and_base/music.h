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
    id type;
    sfMusic *music;
    int volume;
};


struct audio_data_s{
    int master_volume;
    int musics_count;
    music_t *musics;
    sfx_list_t *sounds;
};


#endif //LIBCSFML_MUSIC_H
