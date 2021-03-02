/*
** EPITECH PROJECT, 2020
** free_components_pt2.c
** File description:
** header for free_components_pt2.c
*/

#include <stdlib.h>
#include "../../../include/types.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/struct_shortcuts.h"
#include "../../../include/my.h"

void free_scripts(script_t *scripts)
{
    if (scripts->next)
        free_scripts(scripts->next);
    if (scripts->destroy)
        scripts->destroy(scripts->data);
    if (scripts->name)
        free(scripts->name);
    if (scripts != NULL)
        free(scripts);
    scripts = NULL;
}

void free_script_list(script_list_t *scripts)
{
    if (scripts == NULL)
        return;
    if (scripts->list)
        free_scripts(scripts->list);
    free(scripts);
    scripts = NULL;
}

void free_frames_tab(frame_t *frames)
{
    if (frames != NULL)
        free(frames);
    frames = NULL;
}

void free_anim_list(anim_t *animation)
{
    if (animation->next)
        free_anim_list(animation->next);
    if (animation->frame)
        free_frames_tab(animation->frame);
    if (animation != NULL)
        free(animation);
    animation = NULL;
}

void free_animation(animation_t *animation)
{
    if (animation->list)
        free_anim_list(animation->list);
    if (animation != NULL)
        free(animation);
    animation = NULL;
}