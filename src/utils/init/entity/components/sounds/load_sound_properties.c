/*
** EPITECH PROJECT, 2020
** load_sound_properties.c
** File description:
** load_sound_properties.c
*/

#include "utils/init/common_tags.h"
#include "my.h"
#include "utils/init/load_file.h"

void load_sound_toggle(char *content, int *i, sound_t *sound)
{
    sound->toggle = fill_toogle(content, i);
}

void load_sound_anim(char *content, int *i, sound_t *sound)
{
    sound->type = fill_enum(content, i, anim_enum_tab);
}

void load_sound_name(char *content, int *i, sound_t *sound)
{
    sound->name = extract_value(content, i);
}

void load_sound_music(char *content, int *i, sound_t *sound)
{
    sound->path = extract_value(content, i);
}