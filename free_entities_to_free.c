/*
** EPITECH PROJECT, 2020
** free_entities_to_free.c
** File description:
** free_entities_to_free.c
*/

#include "my_csfml.h"

void add_to_kill_list(game_data_t *data, entity_t *entity)
{
    entity_t *children = entity->children;

    entity->toggle = OFF;
    add_entity_to_list(entity, &G_ACTUAL_SCENE.to_free);
    for (; children; children = children->next)
        add_to_kill_list(data, children);
}

void kill_entities(game_data_t *data, entity_list_t *to_free)
{
    entity_list_t *list = to_free;

    for (;list; list = list->next) {
        if (list->entity && list->entity->on_destroy)
            list->entity->on_destroy(list->entity, G_ACTUAL_SCENEOBJS->scripts, data);
        kill_entity(list->entity, G_ACTUAL_SCENEOBJS);
    }
    free_entites_list(to_free);
    G_ACTUAL_SCENE.to_free = NULL;
}