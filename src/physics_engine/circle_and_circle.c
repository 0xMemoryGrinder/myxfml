/*
** EPITECH PROJECT, 2020
** circle_and_circle.c
** File description:
** header for circle_and_circle.c
*/

#include "my_csfml.h"
#include <math.h>

sfBool circle_and_circle(sfCircleShape *c1, float r1,
sfCircleShape *c2, float r2)
{
    sfVector2f c1_pos = sfCircleShape_getPosition(c1);
    sfVector2f c2_pos = sfCircleShape_getPosition(c2);
    sfVector2f distance = {c2_pos.x - c1_pos.x, c2_pos.y - c1_pos.y};
    float r3 = sqrtf(powf(distance.x, 2.0f) + powf(distance.y, 2.0f));

    if (r3 <= r1 + r2)
        return sfTrue;
    return sfFalse;
}
