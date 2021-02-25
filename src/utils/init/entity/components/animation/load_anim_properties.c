/*
** EPITECH PROJECT, 2020
** set_anim_properties.c
** File description:
** set_anim_properties.c
*/

#include "my_csfml.h"
#include "utils/init/common_tags.h"
#include "my.h"
#include "global_tabs.h"

void load_anim_toggle(char *content, int *i, anim_t *anim)
{
    anim->toggle = fill_toogle(content, i);
}

void load_anim_name(char *content, int *i, anim_t *anim)
{
    anim->name = fill_enum(content, i, anim_enum_tab);
}

void load_anim_frame_action(char *content, int *i, anim_t *anim)
{
    anim->frame_action = (void (*)(game_data_t *, entity_list_t *,
    animation_t *)) fill_function(content, i, anim_func_ptr_tab);
}
