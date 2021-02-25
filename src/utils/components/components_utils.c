/*
** EPITECH PROJECT, 2020
** components_utils.c
** File description:
** header for components_utils.c
*/

#include "my_csfml.h"

void toggle_collider_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_COLLIDER == NULL)
        return;
    E_COLLIDER->toggle = toggle;
}

void toggle_rendersprite_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_RSPRITE == NULL)
        return;
    E_RSPRITE->toggle = toggle;
}

void toggle_transform_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_TRANSFORM == NULL)
        return;
    E_TRANSFORM->toggle = toggle;
}