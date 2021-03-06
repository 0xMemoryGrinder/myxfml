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

int update_anim_state(entity_t * entity)
{
    anim_t *list = E_ANIMATION->list;

    for (; list; list = list->next) {
        if (list->name == E_ANIMATION->actual_anim) {
            E_ANIMATION->actual = list;
            E_ANIMATION->actual_frame = 0;
            sfSprite_setTextureRect(E_RSPRITE->sprite, ACTUAL_CROP.crop);
            return 0;
        }
    }
    E_ANIMATION->actual_anim = E_ANIMATION->actual->name;
    return 1;
}

void update_anim_frame(game_data_t *data, entity_t *entity)
{
    int actual_frame = ACTUAL_FRAME;

    if (my_timer(G_CLOCK, E_ANIMATION->actual->frame
    [actual_frame].trigger, &E_ANIMATION->actual->actual_time))
        ACTUAL_FRAME++;
    if (ACTUAL_FRAME >= E_ANIMATION->actual->frames_count)
        ACTUAL_FRAME = 0;
    sfSprite_setTextureRect(E_RSPRITE->sprite, ACTUAL_CROP.crop);
}

int get_animations_update(game_data_t *data, entity_list_t *animation)
{
    entity_list_t *list = animation;
    int status = 1;

    if (!list || list->entity == NULL)
        return -1;
    for (; status && list; list = list->next) {
        if (list->entity->toggle == OFF || !list->E_ANIMATION
        || list->E_ANIMATION->toggle == OFF)
            continue;
        if (list->E_ANIMATION->actual_anim !=
        list->E_ANIMATION->actual->name) {
            update_anim_state(list->entity);
            continue;
        }
        update_anim_frame(data, list->entity);
        if (list->E_ANIMATION->actual->frame_action != NULL)
            status = list->E_ANIMATION->actual->frame_action(data,
            list->entity, list->E_ANIMATION);
    }
    return status;
}