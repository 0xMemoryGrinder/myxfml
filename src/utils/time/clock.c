/*
** EPITECH PROJECT, 2020
** clock.c
** File description:
** header for clock.c
*/

#include "../../../include/my_csfml.h"

sfBool my_timer(sfClock *clock, sfInt64 trigger, sfInt64 *actual)
{
    sfTime c_time = sfClock_getElapsedTime(clock);
    sfInt64 timer = c_time.microseconds;

    if (!(*actual)) {
        *actual = timer;
    } else {
        if ((*actual - timer) * -1 >= trigger) {
            *actual = timer;
            return sfTrue;
        }
    }
    return sfFalse;
}