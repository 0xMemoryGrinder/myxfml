/*
** EPITECH PROJECT, 2020
** collison.c
** File description:
** header for collison.c
*/

#include <stdlib.h>
#include "../../include/my_csfml.h"
#include "../../include/types_and_base/entity.h"
#include "../../include/types_and_base/scene.h"
#include "../../include/types_and_base/base_components.h"
#include "../../include/types_and_base/struct_shortcuts.h"
#include "../../include/my.h"
#include "../../include/converter.h"

entity_list_t *get_colliders(entity_t *e)
{
    entity_t *entity = e;
    entity_list_t *colliders;

    while(1)
        if (entity->components->collider && E_COLLIDER->toggle)
    return colliders;
}

void inverse_move(entity_t *entity)
{
    E_TRANSFORM->position.x -= E_TRANSFORM->velocity.x;
    E_TRANSFORM->position.y -= E_TRANSFORM->velocity.y;
}

void check_collision(entity_list_t *entity, entity_list_t *collider,
game_data_t *data, entity_list_t *list)
{
    sfIntRect intersect;
    sfIntRect e1 = get_rect(E_COLLIDER->position, E_COLLIDER->dimensions);
    sfIntRect e2 = get_rect(C_COLLIDER->position, C_COLLIDER->dimensions);

    if (sfIntRect_intersects(&e1, &e2, &intersect)) {
        E_COLLIDER->on_collison(entity, collider, data);
        C_COLLIDER->on_collison(collider, entity, data);
    }
}

void collide_physics(scene_t *scene, game_data_t *data)
{
    entity_list_t *entity = scene->objects->colliders;
    entity_list_t *colliders;

    if (!entity->entity || !scene->objects->colliders->next)
        return;
    colliders = scene->objects->colliders->next;
    entity = colliders;
    for (; entity; entity = entity->next) {
        colliders = entity->next;
        for (; colliders; colliders = colliders->next) {

        }
    }
}