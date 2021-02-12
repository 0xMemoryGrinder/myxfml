/*
** EPITECH PROJECT, 2020
** load_sounds_component.c
** File description:
** load_sounds_component.c
*/

#include "load_sounds_component.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/utils/init/common_tags.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../../../include/my.h"
#include "my_puterr.h"
#include "set_sound_properties.h"

void set_sounds_toggle(char *content, int *i, sfx_list_t *sounds)
{
    sounds->toggle = fill_toogle(content, i);
}

sound_t load_sound(char *content, int *i)
{
    sound_t sound;
    int k;

    skip_to_next_tag(content, i, false);
    while (my_strncmp(content + *i, "</sound>", 8)) {
        k = 0;
        while (sound_conf_tag_action[k].tag && my_strncmp(content + *i,
        sound_conf_tag_action[k].tag, sound_conf_tag_action[k].tag_len))
            k++;
        if (!sound_conf_tag_action[k].tag)
            my_puterr("Unrecognized sound tag", __FILE__, __LINE__);
        *i += sound_conf_tag_action[k].tag_len;
        sound_conf_tag_action[k].action(content, i, &sound);
        *i += sound_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }
    return sound;
}

void load_sounds_list(char *content, int *i, sfx_list_t *sounds)
{
    sounds->sfx_count = my_getnbr(content + *i);
    sounds->sfx = malloc_sfx_array(sounds->sfx_count);

    skip_to_next_tag(content, i, false);
    for (int n = 0; n < sounds->sfx_count; n++) {
        sounds->sfx[n] = load_sound(content, i);
    }
}

void load_sounds_component(char *content, int *i, components_t *components)
{
    components->sounds = malloc_sfx_list();
    int k;

    skip_to_next_tag(content, i, false);
    while (my_strncmp(content + *i, "</sounds>", 9)) {
        k = 0;
        while (sounds_conf_tag_action[k].tag && my_strncmp(content + *i,
        sounds_conf_tag_action[k].tag, sounds_conf_tag_action[k].tag_len))
            k++;
        if (!sounds_conf_tag_action[k].tag)
            my_puterr("Unrecognized sounds tag", __FILE__, __LINE__);
        *i += sounds_conf_tag_action[k].tag_len;
        sounds_conf_tag_action[k].action(content, i, components->sounds);
        *i += sounds_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }
}