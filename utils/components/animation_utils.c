/*
** EPITECH PROJECT, 2020
** animation_utils.c
** File description:
** header for animation_utils.c
*/
#include "my_csfml.h"

void toggle_animlist_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_ANIMATION == NULL)
        return;
    E_ANIMATION->toggle = toggle;
}

void change_anim_fromactual(entity_t *entity, anim name, anim_type type)
{
    E_ANIMATION->actual_anim = name;
    if (type != (enum anim_type_e)-1)
        E_ANIMATION->type = type;
    update_anim_state(entity);
}

void change_anim_fromlist(entity_t *list, char *ename,
                          anim name, anim_type type)
{
    entity_t *entity = get_entity_name(list, ename);

    if (entity == NULL)
        return;
    change_anim_fromactual(entity, name, type);
}