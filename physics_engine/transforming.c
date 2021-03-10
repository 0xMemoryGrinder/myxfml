/*
** EPITECH PROJECT, 2020
** transforming.c
** File description:
** header for transforming.c
*/

#include "my_csfml.h"

/*
void transform_text(entity_t *entity)
{
    if (E_TEXT && E_TEXT->toggle == ON) {
        E_COLLIDER->position.x += E_TRANSFORM->velocity.x;
        E_COLLIDER->position.y += E_TRANSFORM->velocity.y;
    }
}*/

void transform_rendersprite(entity_t *entity)
{
    if (E_TRANSFORM == NULL || E_TRANSFORM->toggle == OFF)
        return;
    if (E_RSPRITE && E_RSPRITE->toggle == ON) {
        sfSprite_move(E_RSPRITE->sprite, E_TRANSFORM->velocity);
        sfSprite_setRotation(E_RSPRITE->sprite, E_TRANSFORM->rotation);
    }
}

void transform_collider(entity_t *entity)
{
    if (E_TRANSFORM == NULL || E_TRANSFORM->toggle == OFF)
        return;
    if (E_COLLIDER && E_COLLIDER->toggle == ON) {
        if (E_COLLIDER->is_circle)
            sfCircleShape_move(E_COLLIDER->circ_collider,
           E_TRANSFORM->velocity);
        else
            sfRectangleShape_move(E_COLLIDER->rect_collider,
        E_TRANSFORM->velocity);
        E_COLLIDER->position.x += E_TRANSFORM->velocity.x;
        E_COLLIDER->position.y += E_TRANSFORM->velocity.y;
    }
}

void reset_transform(entity_t *entity)
{
    if (E_TRANSFORM == NULL || E_TRANSFORM->toggle == OFF)
        return;
    E_TRANSFORM->position.x += E_TRANSFORM->velocity.x;
    E_TRANSFORM->position.y += E_TRANSFORM->velocity.y;
    E_TRANSFORM->velocity.x = 0;
    E_TRANSFORM->velocity.y = 0;
}

void transform_updates(game_data_t *data, entity_list_t *transforms)
{
    entity_list_t *list = transforms;

    for (; list ; list = list->next) {
        if (list->entity->toggle == OFF || list->E_TRANSFORM->toggle == OFF)
            continue;
        list->E_TRANSFORM->velocity.x *= data->stats->time->dt;
        list->E_TRANSFORM->velocity.y *= data->stats->time->dt;
        transform_collider(list->entity);
        transform_rendersprite(list->entity);
        reset_transform(list->entity);
    }
}