/*
** EPITECH PROJECT, 2020
** alloc_nodes.c
** File description:
** header for alloc_nodes.c
*/

#include <stdlib.h>
#include "../../../include/my_csfml.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/struct_shortcuts.h"
#include "../../../include/my.h"
#include "../my_puterr.h"

entity_t *malloc_entity_node(void)
{
    entity_t *entity = malloc(sizeof(entity_t));

    if (entity == NULL)
        my_puterr("Error allocating entity", __FILE__, __LINE__);
    entity->name = NULL;
    entity->path = NULL;
    entity->parent = NULL;
    entity->children = NULL;
    entity->next = NULL;
    entity->back = NULL;
    entity->is_in.text = sfFalse;
    entity->is_in.render = sfFalse;
    entity->is_in.collider = sfFalse;
    entity->is_in.script = sfFalse;
    entity->is_in.sfx = sfFalse;
    entity->is_in.interact = sfFalse;
    return entity;
}

entity_list_t *malloc_list_node(void)
{
    entity_list_t *new = malloc(sizeof(entity_list_t));

    if (!new)
        my_puterr("Error allocating entity list node", __FILE__, __LINE__);
    new->next = NULL;
    new->back = NULL;
    new->entity = NULL;
    return new;
}