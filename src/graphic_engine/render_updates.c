/*
** EPITECH PROJECT, 2020
** frames.c
** File description:
** header for frames.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/types_and_base/base_components.h"
#include "../../include/types_and_base/entity.h"
#include "../../include/types_and_base/video.h"
#include "../../include/types_and_base/game.h"
#include "../../include/types_and_base/scene.h"
#include "../../include/types_and_base/struct_shortcuts.h"
#include "../../include/graphic_engine/render_fonctions.h"

void apply_force(entity_t *entity)
{
    E_TRANSFORM->position.x += E_TRANSFORM->velocity.x;
    E_TRANSFORM->position.y += E_TRANSFORM->velocity.y;


    if (E_COLLIDER) {
        E_COLLIDER->position.x += E_TRANSFORM->velocity.x;
        E_COLLIDER->position.y += E_TRANSFORM->velocity.y;
    }

}

void get_render_updates(game_data_t *data, entity_list_t *renders)
{
    entity_list_t *entity = renders;
    for (; entity; entity = entity->next) {
        apply_force(entity->entity);
        sfSprite_setPosition(entity->E_RSPRITE->sprite,
        entity->E_TRANSFORM->position);
        sfRenderWindow_drawSprite(G_WINDOW, entity->E_RSPRITE->sprite, NULL);
    }
}

