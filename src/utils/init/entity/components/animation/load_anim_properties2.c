/*
** EPITECH PROJECT, 2020
** set_anim_properties2.c
** File description:
** set_anim_properties2.c
*/

#include <stdlib.h>
#include "my_xml.h"
#include "my_csfml.h"
#include "my.h"
#include "my_puterr.h"

frame_t load_anim_frame(xmlnode_t *node, int *status)
{
    frame_t frame;
    int status1 = 1;
    int status2 = 1;
    int status3 = 1;
    int status4 = 1;
    int status5 = 1;
    frame.trigger = xml_value_int("duration", node, &status5);
    frame.crop = (sfIntRect){
        xml_value_int("left", node, &status1),
        xml_value_int("top", node, &status2),
        xml_value_int("width", node, &status3),
        xml_value_int("height", node, &status4)
    };

    if (!status1 || !status2 || !status3 || !status4 || !status5)
        *status = 0;
    return frame;
}

int load_anim_frames(xmlnode_t *node, anim_t *anim)
{
    int good = 1;
    anim->frames_count = node->children.size;
    anim->frame = malloc_frames_array(anim->frames_count);

    if (anim->frame == NULL)
        return 0;
    for (int n = 0; n < anim->frames_count; n++) {
        if (my_strcmp(node->children.data[n]->tag, "frame"))
            return (int)my_puterr("Invalid tag name", __FILE__, __LINE__);
        anim->frame[n] = load_anim_frame(node->children.data[n], &good);
        if (!good)
            return 0;
    }
    return 1;
}