/*
** EPITECH PROJECT, 2020
** load_sounds_component.c
** File description:
** load_sounds_component.c
*/

#include "utils/init/entity/components/sounds/load_sounds_component.h"
#include "my_xml.h"
#include "my_csfml.h"
#include "my.h"
#include "my_puterr.h"

int load_sounds_toggle(xmlnode_t *node, sfx_list_t *sounds)
{
    int status = 1;
    sounds->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

sound_t load_sound(xmlnode_t *node, int *status)
{
    sound_t sound;

    if (!load_sound_toggle(node, &sound) || !load_sound_anim(node, &sound) ||
    !load_sound_name(node, &sound) || !load_sound_music(node, &sound)) {
        *status = 0;
        return sound;
    }
    sound.buff = NULL;
    sound.sfx = sfSound_create();
    return sound;
}

int load_sounds_list(xmlnode_t *node, sfx_list_t *sounds)
{
    sounds->sfx_count = node->children.size;
    sounds->sfx = malloc_sfx_array(sounds->sfx_count);
    int good = 1;

    for (int n = 0; n < node->children.size; n++) {
        if (my_strcmp(node->children.data[n]->tag, "sound"))
            return *my_puterr("Unknown sound tag", __FILE__, __LINE__);
        sounds->sfx[n] = load_sound(node->children.data[n], &good);
        if (!good)
            return 0;
    }
    return 1;
}

int load_sounds_component(xmlnode_t *node, components_t *components)
{
    components->sounds = malloc_sfx_list();

    if (components->sounds == NULL ||
        !load_sounds_toggle(node, components->sounds) ||
        !load_sounds_list(node, components->sounds))
        return 0;
    return 1;
}