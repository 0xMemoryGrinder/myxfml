/*
** EPITECH PROJECT, 2020
** clock.c
** File description:
** header for clock.c
*/

#include <stdio.h>
#include "my_csfml.h"

sfBool my_timer(time_stats_t *clock, sfInt64 trigger, sfInt64 *actual)
{
    sfTime c_time = sfClock_getElapsedTime(clock->game_clock);
    sfInt64 timer = c_time.microseconds;

    if (!(*actual)) {
        *actual = timer;
    } else {
        if ((float)(*actual - timer) * -1 >= trigger) {
            *actual = 0;
            return sfTrue;
        }
    }
    return sfFalse;
}