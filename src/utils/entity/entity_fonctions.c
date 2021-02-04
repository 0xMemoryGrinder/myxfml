/*
** EPITECH PROJECT, 2020
** entity_fonctions.c
** File description:
** header for entity_fonctions.c
*/

#include <stdlib.h>
#include "../../../include/my_csfml.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/struct_shortcuts.h"
#include "../../../include/my.h"

void swap_actual_tolist(entity_list_t **from, entity_list_t **to)
{
    entity_t *e = pop_actual_fromlist(from);

    add_entity_to_list(e, to);
}

void remove_actual_fromlist(entity_list_t **entity)
{
    entity_t *e = pop_actual_fromlist(entity);

    free_entity(e);
}

entity_t *pop_actual_fromlist(entity_list_t **list)
{
    entity_t *to_pop = (*list)->entity;
    entity_list_t *to_delete = (*list);

    if((*list)->back && (*list)->next) {
        (*list)->back->next = (*list)->next;
        (*list) = (*list)->back;
    } else if ((*list)->back) {
        (*list)->back->next = NULL;
        (*list) = (*list)->back;
    } else {
        (*list) = (*list)->next;
    }
    to_delete->next = NULL;
    to_delete->back = NULL;
    to_delete->entity = NULL;
    free(to_delete);
    return to_pop;
}

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


void init_list(entity_t *entity, entity_list_t **list)
{
    if (!(*list)) {
        (*list) = malloc_list_node();
        (*list)->entity = entity;
    } else {
        (*list)->next = malloc_list_node();
        (*list)->next->entity = entity;
        (*list)->next->back = (*list);
    }
}

void add_entity_to_list(entity_t *entity, entity_list_t **list)
{
    entity_list_t *new;

    if (!(*list) || (!(*list)->next && !(*list)->back)) {
        init_list(entity, list);
        return;
    } new = malloc_list_node();
    new->entity = entity;
    if ((*list)->back && (*list)->next) {
        new->next = (*list);
        (*list)->back->next = new;
        (*list)->back = new;
        new->back = (*list)->back;
        (*list) = (*list)->back;
    } else if (!(*list)->back) {
        new->next = (*list);
        (*list)->back = new;
        (*list) = (*list)->back;
    } else {
        new->back = (*list);
        (*list)->next = new;
    }
}

