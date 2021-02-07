/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** header for create.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../../include/my_csfml.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/my.h"
#include "../my_puterr.h"

components_t *malloc_components(void)
{
    components_t *cmp = malloc(sizeof(components_t));

    if (cmp == NULL)
        my_puterr("Error : malloc component structure", __FILE__, __LINE__);
    cmp->render = NULL;
    cmp->transform = NULL;
    cmp->texts = NULL;
    cmp->animation = NULL;
    cmp->scripts = NULL;
    cmp->interact = NULL;
    cmp->collider = NULL;
    cmp->sounds = NULL;
    return cmp;
}

collider_t *malloc_collider(void)
{
    collider_t *new = malloc(sizeof(collider_t));

    if (new == NULL)
        my_puterr("Error : malloc collider structure", __FILE__, __LINE__);
    new->position = (sfVector2f){0, 0};
    new->dimensions = (sfVector2f){0, 0};
    new->on_collison = NULL;
    new->is_rs_linked = OFF;
    return new;
}

animation_t *malloc_animations(void)
{
    animation_t *anim = malloc(sizeof(animation_t));

    if (anim == NULL)
        my_puterr("Error : malloc animations structure", __FILE__, __LINE__);
    anim->toggle = OFF;
    anim->actual = NULL;
    anim->actual_frame = 0;
    anim->list = NULL;
    anim->type = IDLE;
    return anim;
}


anim_t *malloc_anim_frame(void)
{
    anim_t *anim = malloc(sizeof(anim_t));

    if (anim == NULL)
        my_puterr("Error : malloc anim frame node", __FILE__, __LINE__);
    anim->toggle = OFF;
    anim->frames_count = 0;
    anim->frame = NULL;
    anim->actual_time = 0;
    anim->frame_action = NULL;
    anim->next = NULL;
    anim->name = IDLE_STATIC;
    return anim;
}

frame_t *malloc_frames_array(int count)
{
    frame_t *frames = malloc(sizeof(frame_t) * (count + 1));

    if (frames == NULL )
        my_puterr("Error : malloc frames array", __FILE__, __LINE__);
    for (int i = 0; i < count; i++) {
        frames[i].trigger = 0;
        frames[i].crop = (sfIntRect){0, 0, 0, 0};
    }
    return frames;
}