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


//#include "my_csfml.h"

//
//  DEFINITON
//
#define SECONDS(seconds) (seconds * 1000000)

sfBool my_timer(sfClock *clock, int trigger, int *actual);
//
//  IMPLEMENTATION
//


sfBool my_timer(sfClock *clock, int trigger, int *actual)
{
    sfTime c_time = sfClock_getElapsedTime(clock);
    sfInt64 timer = c_time.microseconds / 1000000;

    if (!(*actual)) {
        *actual = timer;
    } else {
        *actual -= timer;
        *actual *= -1;
        if ( *actual >= trigger) {
            *actual = 0;
            return sfTrue;
        }
    }
    return sfFalse;
}

#endif //LIBCSFML_CLOCK_H
