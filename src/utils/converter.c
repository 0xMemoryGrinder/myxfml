/*
** EPITECH PROJECT, 2020
** converter.c
** File description:
** header for converter.c
*/

#include "../../include/my_csfml.h"

sfIntRect get_rect(sfVector2f pos, sfVector2f dim)
{
    sfIntRect r;
    r.left = (int)pos.x;
    r.top = (int)pos.y;
    r.height = (int)dim.y;
    r.width = (int)dim.x;
    return r;
}