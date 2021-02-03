/*
** EPITECH PROJECT, 2020
** collison.c
** File description:
** header for collison.c
*/

#include <stdlib.h>
#include "my_csfml.h"
#include "entity.h"
#include "scene.h"
#include "base_components.h"
#include "struct_shortcuts.h"
#include "../include/my.h"

void free_entity(entity_t* entity)
{
    E_COLLIDER->
}

void add_collider(entity_t *e)
{
    entity_t *entity = e;
    E_COLLIDER->toggle = ON;

}







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

sfIntRect get_rect(sfVector2f pos, sfVector2f dim)
{
    sfIntRect r;
    r.left = pos.x;
    r.top = pos.y;
    r.height = dim.y;
    r.width = dim.x;
    return r;
}


void inverse_move(entity_t *entity)
{
    E_TRANSFORM->position.x -= E_TRANSFORM->velocity.x;
    E_TRANSFORM->position.y -= E_TRANSFORM->velocity.y;
}


void check_collision(entity_t *entity, entity_t *collider, game_data_t *data)
{
    sfIntRect intersect;
    sfIntRect e1;
    sfIntRect e2;

    set_rect(&e1, E_COLLIDER->position, E_COLLIDER->dimensions);
    set_rect(&e2, collider->components->collider->position, collider->components->collider->dimensions);
    if (sfIntRect_intersects(&e1, &e2, &intersect)) {
        E_COLLIDER->on_collison(entity, collider, data);
        collider->components->collider->on_collison(collider, entity, data);
    }
}

void collide_physics(scene_t *scene, game_data_t *data, sfBool is_update)
{
    static sfBool no_colliders = sfFalse;
    static entity_t *colliders = NULL;
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


//
//  Collision Script Idea
//




/*
typedef enum {GET, SET, }script_action;

void *script_basic(entity_t *entity, script_action to_do)
{
    static player_stats_t objects = get_data(entity->data, 'INVENTORY');


}


void *actual_capacities_gui(entity_t *entity, script_action to_do)
{
    static entity_t *pl = NULL;
    if (to_do == INIT)
        pl = entity;

}

void on_collison(entity_list_t *self, entity_list_t *collider, game_data_t *data)
{
    static void *zombi_info;
    void *collider_info;

    if (collider is projectile) {
        collider_info = get_projectile_info(collider);
        zombie_info.life -= (collider_info.damage - zombie_info.resitance);
        if (!zombie_info.life)
            self->change_anim(DYING);
        else
            self->change_anim(HURT);
        remove_entity_from_list(collider);
        collide_physics();
    }
}
*/