/*
** EPITECH PROJECT, 2020
** sfx_updates.c
** File description:
** header for sfx_updates.c
*/

#include "../../include/my_csfml.h"

void check_sound_state(game_data_t *data, sfx_list_t *list, int i)
{
    sfSoundStatus state = sfSound_getStatus(list->sfx[i].sfx);

    if (state == sfPlaying) {
        sfSound_setVolume(list->sfx[i].sfx, G_SFXV);
        list->sfx[i].toggle = OFF;
    } else {
        if (list->sfx[i].toggle == ON) {
            list->sfx[i].buff = sfSoundBuffer_createFromFile(list->sfx[i].path);
            sfSound_setBuffer(list->sfx[i].sfx, list->sfx[i].buff);
            sfSound_setVolume(list->sfx[i].sfx, G_SFXV);
            sfSound_play(list->sfx[i].sfx);
            list->sfx[i].toggle = OFF;
        } else {
            sfSoundBuffer_destroy(list->sfx[i].buff);
            sfSound_destroy(list->sfx[i].sfx);
            list->sfx[i].sfx = sfSound_create();
        }
    }
}

void sfx_array_updates(game_data_t *data, sfx_list_t *list)
{
    for (int i = 0; i < list->sfx_count; i++) {
        check_sound_state(data, list, i);
    }
}

void sfx_engine(game_data_t *data, entity_list_t *list)
{
    entity_list_t *sfx_list = list;

    for (; sfx_list; sfx_list = sfx_list->next) {
        if (sfx_list->entity->toggle == OFF ||
        sfx_list->E_SOUND->toggle == OFF)
            continue;
        sfx_array_updates(data, sfx_list->E_SOUND);
    }
}