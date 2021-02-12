/*
** EPITECH PROJECT, 2020
** animation updates.c
** File description:
** header for animation.c
*/

#include <stdlib.h>
#include "../../include/types_and_base/base_components.h"
#include "../../include/types_and_base/entity.h"
#include "../../include/types_and_base/video.h"
#include "../../include/types_and_base/game.h"
#include "../../include/types_and_base/scene.h"
#include "../../include/types_and_base/clock.h"
#include "../../include/types_and_base/struct_shortcuts.h"

void update_anim_state(entity_t * entity)
{
    anim_t * list = E_ANIMATION->list;

    for (; list; list = list->next) {
        if (list->name == E_ANIMATION->actual_anim) {
            E_ANIMATION->actual = list;
            E_ANIMATION->actual_frame = 0;
            break;
        }
    }
    if (list == NULL) {
        E_ANIMATION->actual_anim = E_ANIMATION->actual->name;
    }
}

void update_anim_frame(game_data_t *data, entity_t *entity)
{
    int actual_frame = ACTUAL_FRAME;

    if (my_timer(G_CLOCK, E_ANIMATION->actual->frame
    [actual_frame].trigger, &E_ANIMATION->actual->actual_time))
        ACTUAL_FRAME++;
    if (ACTUAL_FRAME >= E_ANIMATION->actual->frames_count)
        ACTUAL_FRAME = 0;
}

void get_animations_update(game_data_t *data, entity_list_t *animation)
{
    entity_list_t *list = animation;

    for (; list; list = list->next) {
        if (list->entity->toggle == OFF || list->E_ANIMATION->toggle == OFF)
            continue;
        if (list->E_ANIMATION->actual_anim != list->E_ANIMATION->actual->name)
            update_anim_state(list->entity);
        update_anim_frame(data, list->entity);
        sfSprite_setTextureRect(list->E_RSPRITE->sprite,
        list->A_CROP[list->ACTUAL_FRAME].crop);
        if (list->E_ANIMATION->actual->frame_action != NULL)
            list->E_ANIMATION->actual->frame_action(data,
            list, list->E_ANIMATION);
    }
}