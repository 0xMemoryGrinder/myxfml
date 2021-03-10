/*
** EPITECH PROJECT, 2020
** rectangle_and_rectangle.c
** File description:
** header for rectangle_and_rectangle.c
*/

#include "my_csfml.h"

sfBool rectangle_and_rectangle(sfRectangleShape *r1_coll,
sfRectangleShape *r2_coll)
{
    sfFloatRect r1 = sfRectangleShape_getGlobalBounds(r1_coll);
    sfFloatRect r2 = sfRectangleShape_getGlobalBounds(r2_coll);

    if (sfFloatRect_intersects(&r1, &r2, NULL))
        return sfTrue;
    return sfFalse;
}