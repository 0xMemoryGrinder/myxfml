/*
** EPITECH PROJECT, 2020
** load_collider_form.c
** File description:
** header for load_collider_form.c
*/

#include "my_csfml.h"

int init_circle_collider(components_t *components)
{
    components->collider->circ_collider = sfCircleShape_create();
    if (components->collider->circ_collider == NULL)
        return 0;
    sfCircleShape_setRadius(components->collider->circ_collider,
                            components->collider->radius);
    sfCircleShape_setOrigin(components->collider->circ_collider,
    (sfVector2f){components->collider->radius,
    components->collider->radius});
    sfCircleShape_setPosition(components->collider->circ_collider,
    components->collider->position);
    sfCircleShape_setFillColor(components->collider->circ_collider, sfBlue);
    components->collider->rect_collider = NULL;
    return 1;
}

int init_rectangle_collider(components_t *components)
{
    components->collider->rect_collider = sfRectangleShape_create();
    if (components->collider->rect_collider == NULL)
        return 0;
    sfRectangleShape_setSize(components->collider->rect_collider,
    components->collider->dimensions);
    sfRectangleShape_setPosition(components->collider->rect_collider,
    components->collider->position);
    sfRectangleShape_setFillColor(components->collider->rect_collider, sfBlue);
    components->collider->circ_collider = NULL;
    return 1;
}