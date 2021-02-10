/*
** EPITECH PROJECT, 2020
** set_sound_properties.c
** File description:
** set_sound_properties.c
*/

#include "set_sound_properties.h"
#include "../../../common_tags.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/my.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../my_puterr.h"

void set_sound_toggle(char *content, int *i, sound_t *sound)
{
    sound->toggle = fill_toogle(content, i);
}

void set_sound_anim(char *content, int *i, sound_t *sound)
{
    sound->type = fill_enum(content, i);
}

void set_sound_name(char *content, int *i, sound_t *sound)
{
    sound->name = extract_value(content, i);
}

void set_sound_music(char *content, int *i, sound_t *sound)
{
    char *path = extract_value(content, i);
    sound->buff = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(sound->sfx, sound->buff);
    free(path);
}