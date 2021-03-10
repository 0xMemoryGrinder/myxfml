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
    entity_list_t *list = renders;

    if (list == NULL || list->entity == NULL)
        return;
    for (; list; list = list->next) {
        if (list->entity->toggle == OFF || list->E_RSPRITE->toggle == OFF)
            continue;
        sfRenderWindow_drawSprite(G_WINDOW, list->E_RSPRITE->sprite, NULL);
        if (list->E_TEXT != NULL && list->E_TEXT->toggle == ON)
            update_text(data, list->E_TEXT, list->entity);
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