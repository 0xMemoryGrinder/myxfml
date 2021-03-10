/*
** EPITECH PROJECT, 2020
** load_sound_properties.c
** File description:
** load_sound_properties.c
*/

#include "my_xml.h"
#include "utils/init/common_tags.h"
#include "my.h"

int load_sound_toggle(xmlnode_t *node, sound_t *sound)
{
    int status = 1;
    sound->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_sound_anim(xmlnode_t *node, sound_t *sound)
{
    int status = 1;
    char *content = xml_value_str("anim", node, &status);

    if (!status)
        return 0;
    if (content)
        sound->type = fill_enum(content, anim_enum_tab, &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

int load_sound_name(xmlnode_t *node, sound_t *sound)
{
    int status = 1;
    sound->name = xml_value_str("name", node, &status);

    if (!status || !sound->name)
        return 0;
    return 1;
}

int load_sound_music(xmlnode_t *node, sound_t *sound)
{
    int status = 1;
    sound->path = xml_value_str("path", node, &status);

    if (!status || !sound->path)
        return 0;
    return 1;
}