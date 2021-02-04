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

entity_t *malloc_entity_node(void)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        exit(84);
    new->next = NULL;
    new->back = NULL;
    return new;
}

entity_list_t *malloc_list_node(void)
{
    entity_list_t *new = malloc(sizeof(entity_list_t));

    if (!new)
        exit(84);
    new->next = NULL;
    new->back = NULL;
    new->entity = NULL;
    return new;
}