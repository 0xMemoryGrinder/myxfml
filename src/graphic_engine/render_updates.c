/*
** EPITECH PROJECT, 2020
** frames.c
** File description:
** header for frames.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_csfml.h"
#include "my.h"

void get_render_updates(game_data_t *data, entity_list_t *renders)
{
    entity_list_t *entity = renders;

    if (entity == NULL || entity->entity == NULL)
        return;
    for (; entity; entity = entity->next) {
        if (entity->entity->toggle == OFF || entity->E_RSPRITE->toggle == OFF)
            continue;
        sfRenderWindow_drawSprite(G_WINDOW, entity->E_RSPRITE->sprite, NULL);
        if (entity->E_TEXT != NULL && entity->E_TEXT->toggle == ON)
            update_text(data, entity->E_TEXT, entity->entity);
    }
}

int graphic_engine(game_data_t *data)
{
    if (!get_animations_update(data, G_ACTUAL_SCENEOBJS->render))
        return 0;
    G_ACTUAL_SCENEOBJS->render = mergeSort(G_ACTUAL_SCENEOBJS->render);
    get_render_updates(data, G_ACTUAL_SCENEOBJS->render);
    get_render_updates(data, G_ACTUAL_SCENEOBJS->gui);
    get_texts_updates(data, G_ACTUAL_SCENEOBJS->text);
    return 1;
}