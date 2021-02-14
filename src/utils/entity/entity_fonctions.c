/*
** EPITECH PROJECT, 2020
** entity_fonctions.c
** File description:
** header for entity_fonctions.c
*/

#include <stdlib.h>
#include "../../../include/my_csfml.h"
#include "../../../include/my.h"

entity_t *get_entity_name(entity_t *entity, const char *name)
{
    entity_t *children = entity->children;
    entity_t *to_return = NULL;

    if (entity != NULL && !my_strcmp(entity->name, name))
        return entity;
    else if (children != NULL)
        to_return = get_entity_name(children->next, name);
    if (entity->next && !to_return)
        return get_entity_name(entity->next, name);
    return to_return;
}

void add_entity(entity_t *entity, entity_t **list)
{
    (*list)->back = entity;
    (*list) = (*list)->back;

}


void init_list(entity_t *entity, entity_list_t **list)
{
    if (!(*list)) {
        (*list) = malloc_list_node();
        (*list)->entity = entity;
    } else {
        if (!(*list)->entity)
            (*list)->entity = entity;
        else {
            (*list)->next = malloc_list_node();
            (*list)->next->entity = entity;
            (*list)->next->back = (*list);
        }
    }
}

void add_entity_to_list(entity_t *entity, entity_list_t **list)
{
    entity_list_t *new;

    if (!(*list)->entity) {
        (*list)->entity = entity;
        return;
    }
    if (!(*list)->back) {
        (*list)->back = malloc_list_node();
        (*list)->back->next = (*list);
        (*list) = (*list)->back;
        (*list)->entity = entity;
    } else if (!(*list)->next) {
        (*list)->next = malloc_list_node();
        (*list)->next->entity = entity;
        (*list)->next->back = (*list);
    }
}

