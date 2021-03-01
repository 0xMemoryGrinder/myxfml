/*
** EPITECH PROJECT, 2020
** set_animation_properties.c
** File description:
** set_animation_properties.c
*/

#include <stdlib.h>
#include "my_xml.h"
#include "utils/init/common_tags.h"
#include "my.h"
#include "global_tabs.h"

int load_animation_toggle(xmlnode_t *node, animation_t *animation)
{
    int status = 1;
    animation->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_animation_actual_anim(xmlnode_t *node, animation_t *animation)
{
    int status = 1;
    char *content = xml_value_str("actual_anim", node, &status);

    if (!status)
        return 0;
    animation->actual_anim = fill_enum(content, anim_enum_tab, &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

int load_animation_anim_type(xmlnode_t *node, animation_t *animation)
{
    int status = 1;
    char *content = xml_value_str("anim_type", node, &status);

    if (!status)
        return 0;
    animation->type = fill_enum(content, anim_type_enum_tab, &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

int load_animation_actual_frame(xmlnode_t *node, animation_t *animation)
{
    int status = 1;

    animation->actual_frame = xml_value_int("actual_frame", node, &status);
    if (!status)
        return 0;
    return 1;
}