/*
** EPITECH PROJECT, 2020
** set_anim_properties2.c
** File description:
** set_anim_properties2.c
*/

#include <stdlib.h>
#include "my_csfml.h"
#include "my.h"
#include "utils/init/load_file.h"
#include "my_puterr.h"

char **load_tab(char *str, char sep, int nb)
{
    char **frame_trigger = my_str_to_tab(str, sep);
    int i = 0;

    for (i = 0; frame_trigger[i]; i++);
    if (i != nb)
        my_puterr("Error in frame config", __FILE__, __LINE__);
    return frame_trigger;
}

frame_t load_anim_frame(char *content, int *i)
{
    frame_t frame;
    char *value = extract_value(content, i);
    char **frame_trigger = load_tab(value, ':', 2);
    char **crop = load_tab(frame_trigger[0], ' ', 4);

    frame.trigger = my_getnbr(frame_trigger[1]);
    frame.crop = (sfIntRect){
        my_getnbr(crop[0]), my_getnbr(crop[1]),
        my_getnbr(crop[2]), my_getnbr(crop[3])
    };
    free(frame_trigger[0]);
    free(frame_trigger[1]);
    free(frame_trigger);
    free(crop[0]);
    free(crop[1]);
    free(crop[2]);
    free(crop[3]);
    free(crop);
    return frame;
}

void load_anim_frames(char *content, int *i, anim_t *anim)
{
    anim->frames_count = my_getnbr(content + *i);
    anim->frame = malloc_frames_array(anim->frames_count);

    for (int n = 0; n < anim->frames_count; n++) {
        skip_to_next_tag(content, i, OPEN);
        if (my_strncmp(content + *i, "<frame>", 7))
            my_puterr("Error in anim frame config", __FILE__, __LINE__);
        *i += 7;
        anim->frame[n] = load_anim_frame(content, i);
    }
    *i += 1;
    skip_to_next_tag(content, i, CLOSE);
}