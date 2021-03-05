/*
** EPITECH PROJECT, 2020
** clock.h
** File description:
** header for clock.c
*/

#ifndef LIBCSFML_CLOCK_H
#define LIBCSFML_CLOCK_H

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>


//#include "src.h"

//
//  DEFINITON
//
#define SECONDS(seconds) (seconds * 1000000)

sfBool my_timer(time_stats_t *clock, sfInt64 trigger, sfInt64 *actual);

#endif //LIBCSFML_CLOCK_H
