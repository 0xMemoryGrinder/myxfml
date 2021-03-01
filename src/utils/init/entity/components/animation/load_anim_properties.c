/*
** EPITECH PROJECT, 2020
** set_anim_properties.c
** File description:
** set_anim_properties.c
*/

#include "my_xml.h"
#include "utils/init/common_tags.h"
#include "my.h"
#include "global_tabs.h"

int load_anim_toggle(xmlnode_t *node, anim_t *anim)
{
    int status = 1;

    anim->toggle = xml_toggle("toggle", node, &status);
    if (!status)
        return 0;
    return 1;
}

int load_anim_name(xmlnode_t *node, anim_t *anim)
{
    int status = 1;
    char *content = xml_value_str("name", node, &status);

    if (!status)
        return 0;
    anim->name = fill_enum(content, anim_enum_tab, &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

int load_anim_frame_action(xmlnode_t *node, anim_t *anim)
{
    int status = 1;
    char *content = xml_value_str("action", node, &status);

    if (!status)
        return 0;
    anim->frame_action = (void (*)(game_data_t *, entity_list_t *,
    animation_t *)) fill_function(content, anim_func_ptr_tab, &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}
