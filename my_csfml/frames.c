/*
** EPITECH PROJECT, 2020
** frames.c
** File description:
** header for frames.c
*/

#include <stdlib.h>
#include "base_components.h"
#include "entity.h"
#include "video.h"
#include "game.h"
#include "scene.h"
#include "struct_shortcuts.h"

static void get_entity_update(entity_t *entity , sfRenderWindow *w)
{
    if (E_RSPRITE->toggle) {
        sfSprite_setTextureRect(E_RSPRITE->sprite, E_RSPRITEcrop);
        sfSprite_setPosition(E_RSPRITE->sprite, E_TRANSFORM->position);
        sfRenderWindow_drawSprite(w, E_RSPRITE->sprite, NULL);
    }
}

void get_entities_updates(entity_list_t *entity_list, sfRenderWindow *w)
{
    entity_list_t *entities;
    entity_list_t *binded;
    if (!entity_list || !entity_list->entity)
        return;
    entities = entity_list;
    for (; entities; entities = entities->next) {
        get_entity_update(entities->entity, w);
        binded = entities->entity->children;
        if (binded)
            get_entities_updates(binded, w);
    }
}

void get_frame_update(game_data_t *data)
{
    /*
    sfRenderWindow_clear(G_WINDOW, sfBlack);
    get_entites_updates(GE_GLOBAL, G_WINDOW);
    get_entites_updates(GE_SCENE, G_WINDOW);
    get_entites_updates(GE_PLAYER, G_WINDOW);
    get_entites_updates(GE_GUI, G_WINDOW);
    sfRenderWindow_display(G_WINDOW);
     */
}

