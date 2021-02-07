/*
** EPITECH PROJECT, 2020
** video.h
** File description:
** header for video.c
*/

#ifndef LIBCSFML_VIDEO_H
#define LIBCSFML_VIDEO_H

#include "../types.h"

struct video_data_s{
    int fps;
    int width;
    int height;
    int scale_factor;
    char *game_title;
    sfVideoMode mode;
    sfRenderWindow *window;
};

#endif //LIBCSFML_VIDEO_H
