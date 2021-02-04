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

void update_colliders(entity_t *objects)
{
    entity_t *entity = objects;

    while (entity) {
        if (E_COLLIDER->is_rs_linked) {
            E_COLLIDER->dimensions.y = E_RSPRITE->crop_list->crop.height;
            E_COLLIDER->dimensions.x = E_RSPRITE->crop_list->crop.width;
        }
        entity = entity->next;
    }

}

void inverse_move(entity_t *entity)
{
    E_TRANSFORM->position.x -= E_TRANSFORM->velocity.x;
    E_TRANSFORM->position.y -= E_TRANSFORM->velocity.y;
}

void check_collision(entity_t *entity, entity_t *collider,
game_data_t *data, entity_list_t *list)
{
    sfIntRect intersect;
    sfIntRect e1 = get_rect(E_COLLIDER->position, E_COLLIDER->dimensions);
    sfIntRect e2 = get_rect(C_COLLIDER->position, C_COLLIDER->dimensions);

    if (sfIntRect_intersects(&e1, &e2, &intersect)) {
        E_COLLIDER->on_collison(entity, collider, data, list);
        C_COLLIDER->on_collison(collider, entity, data, list);
    }
}

void collide_physics(scene_t *scene, game_data_t *data, sfBool is_update)
{

    entity_t *entity;
    entity_t *collider;

    if (!colliders || is_update)
        colliders = get_colliders(scene->entity_list);
    entity = colliders;
    update_colliders(entity);
    if (no_colliders || !colliders->next)
        return;
    entity = colliders;
    for (; entity; entity = entity->next) {
        collider = entity->next;
        for (; collider; collider = collider->next) {
            check_collision(entity, collider, data);
        }
    }
}