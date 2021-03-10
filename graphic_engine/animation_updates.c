/*
** EPITECH PROJECT, 2020
** animation updates.c
** File description:
** header for animation.c
*/

#include <stdlib.h>
#include "my_csfml.h"

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

int update_anim_frame(game_data_t *data, entity_t *entity)
{
    int actual_frame = ACTUAL_FRAME;
    int status = 1;

    if (my_timer(G_CLOCK, E_ANIMATION->actual->frame
    [actual_frame].trigger, &E_ANIMATION->actual->actual_time))
        ACTUAL_FRAME++;
    if (E_ANIMATION->actual->frame_action != NULL)
        status = E_ANIMATION->actual->frame_action(data,
        entity, E_ANIMATION);
    if (ACTUAL_FRAME >= E_ANIMATION->actual->frames_count)
        ACTUAL_FRAME = 0;
    sfSprite_setTextureRect(E_RSPRITE->sprite, ACTUAL_CROP.crop);
    return status;
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
         status = update_anim_frame(data, list->entity);
    }
    return status;
}