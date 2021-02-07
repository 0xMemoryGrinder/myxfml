/*
** EPITECH PROJECT, 2020
** y_sorting_sprites.c
** File description:
** header for y_sorting_sprites.c
*/

#include <stdlib.h>
#include "../../include/types_and_base/base_components.h"
#include "../../include/types_and_base/entity.h"
#include "../../include/types_and_base/video.h"
#include "../../include/types_and_base/game.h"
#include "../../include/types_and_base/scene.h"
#include "../../include/types_and_base/struct_shortcuts.h"

entity_list_t *split(entity_list_t *head);

int get_y_pivot(entity_list_t *entity)
{
    return entity->E_TRANSFORM->position.y +
    (entity->E_ANIMATION->actual->frame[entity->ACTUAL_FRAME].crop.height *
    entity->E_TRANSFORM->scale.y);
}

static entity_list_t *merge(entity_list_t *first, entity_list_t *second)
{
    int f;
    int s;

    if (!first)
        return second;
    if (!second)
        return first;
    f = get_y_pivot(first);
    s = get_y_pivot(second);
    if (f <= s) {
        first->next = merge(first->next, second);
        first->next->back = first;
        first->back = NULL;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->back = second;
        second->back = NULL;
        return second;
    }
}

entity_list_t *split(entity_list_t *head)
{
    entity_list_t *fast = head;
    entity_list_t *slow = head;
    entity_list_t *tmp;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    tmp = slow->next;
    slow->next = NULL;
    return tmp;
}

entity_list_t *mergeSort(entity_list_t *head)
{
    entity_list_t *second;

    if (!head || !head->next)
        return head;
    second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head,second);
}