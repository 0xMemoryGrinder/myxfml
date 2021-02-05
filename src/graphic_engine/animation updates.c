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

void update_anim_frame(game_data_t *data, entity_list_t *list)
{
    int actual_frame = list->ACTUAL_FRAME;

    if (my_timer(G_CLOCK, list->E_ANIMATION->actual->frame
    [actual_frame].trigger, &list->E_ANIMATION->actual->actual_time))
        list->ACTUAL_FRAME++;
    if (list->ACTUAL_FRAME >= list->E_ANIMATION->actual->frames_count)
        list->ACTUAL_FRAME = 0;
}

void get_animations_update(game_data_t *data, entity_list_t *animation)
{
    entity_list_t *list = animation;

    for (; list; list = list->next) {
        update_anim_frame(data, list);
        sfSprite_setTextureRect(list->E_RSPRITE->sprite,
        list->A_CROP[list->ACTUAL_FRAME].crop);
        if (list->E_ANIMATION->actual->frame_action != NULL)
            list->E_ANIMATION->actual->frame_action(data,
            list, list->E_ANIMATION);
    }
}