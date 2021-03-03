/*
** EPITECH PROJECT, 2020
** colliders.c
** File description:
** header for colliders.c
*/

#include "my_csfml.h"

void get_sprite_collider(entity_t *entity, float x, float y) {
    float pos_x;
    float pos_y;
    sfVector2f pos = sfSprite_getPosition(E_RSPRITE->sprite);
    if (x == 1)
        pos_x = 1;
    else
        pos_x = (1 - x) * 0.5f;
    if (y == 1)
        pos_y = 1;
    else
        pos_y = (1 - y);
    E_COLLIDER->dimensions.x = ACTUAL_CROP.crop.width * x;
    E_COLLIDER->position.x = pos.x +
                             ACTUAL_CROP.crop.width * pos_x;
    E_COLLIDER->dimensions.y = ACTUAL_CROP.crop.height * y;
    E_COLLIDER->position.y = pos.y +
                             ACTUAL_CROP.crop.height * pos_y;
    sfRectangleShape_setSize(E_COLLIDER->rect_collider,
                             E_COLLIDER->dimensions);
    sfRectangleShape_setPosition(E_COLLIDER->rect_collider,
                                 E_COLLIDER->position);
}