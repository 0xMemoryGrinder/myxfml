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

void check_collision(entity_list_t *entity, entity_list_t *collider,
game_data_t *data)
{
    sfIntRect intersect;
    sfIntRect e1 = get_rect(entity->E_COLLIDER->position,
    entity->E_COLLIDER->dimensions);
    sfIntRect e2 = get_rect(collider->E_COLLIDER->position,
    collider->E_COLLIDER->dimensions);

    if (sfIntRect_intersects(&e1, &e2, &intersect)) {
        entity->E_COLLIDER->on_collison(entity, collider, data);
        if (collider != NULL && entity != NULL)
            collider->E_COLLIDER->on_collison(collider, entity, data);
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
            check_collision(entity, colliders, data);
        }
    }
}