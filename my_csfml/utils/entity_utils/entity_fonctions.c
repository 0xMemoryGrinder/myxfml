/*
** EPITECH PROJECT, 2020
** entity_fonctions.c
** File description:
** header for entity_fonctions.c
*/

#include <stdlib.h>
#include "../../my_csfml.h"
#include "../../entity.h"
#include "../../scene.h"
#include "../../base_components.h"
#include "../../struct_shortcuts.h"
#include "../../../include/my.h"




void remove_entity(entity_t *entity)
{
    entity_t *to_delete = entity;

    if (entity->back && entity->next)
        entity->back->next = entity->next;
    if (!entity->back) {
        entity = entity->next;
        entity->back = NULL;
    }
    if (!entity->next)
        entity = entity->back;
    if (to_delete->children)
        free_entity_list(entity->children);
    free_entity(to_delete);
}

entity_t *get_entity(entity_t *entity, const char *name)
{
    entity_t *children = entity->children;
    entity_t *to_return = NULL;

    if (entity != NULL && my_strcmp(entity->name, name))
        return entity;
    else if (children != NULL)
        to_return = get_entity(children->next, name);
    if (entity->next && !to_return)
        return get_entity(entity->next, name);
    return to_return;
}

void add_entity(entity_t *entity, entity_t **list)
{
    if (*list != NULL) {
        entity->next = *list;
        (*list)->back = entity;
    }
    *list = entity;
}

void add_entity_to_list(entity_t *entity, entity_list_t **list)
{
    if ((*list)->entity != NULL) {
        if (!(*list)->back) {
            (*list)->back = malloc(sizeof(entity_list_t));
            (*list)->back->entity = entity;
            (*list)->back->next = (*list);
            (*list) = (*list)->back;
        }
        (*list)->back = entity;
    }
    (*list)->entity = entity;

}