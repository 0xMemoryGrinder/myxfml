/*
** EPITECH PROJECT, 2020
** core_engine.c
** File description:
** header for core_engine.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "utils/init_xfml.h"
#include "my_csfml.h"
#include "my_puterr.h"
#include "audio_engine/audio_engine.h"
#include "scripts_engine/script_updates.h"
#include "physics_engine/physics.h"
#include "graphic_engine/render_fonctions.h"
#include "input_engine/input_engine.h"

void start_game(game_data_t *data)
{
    if (data->game_settings->video->is_fullscreen)
        G_WINDOW = sfRenderWindow_create(sfVideoMode_getDesktopMode(),
        data->game_settings->video->game_title, sfFullscreen, NULL);
    else
        G_WINDOW = sfRenderWindow_create(data->game_settings->video->mode,
        data->game_settings->video->game_title, sfClose, NULL);
    data->stats->time->game_clock = sfClock_create();
}

void input_engine(game_data_t *data)
{
    sfVector2f right;
    sfVector2f left;

    while (sfRenderWindow_pollEvent(G_WINDOW, data->stats->event)) {
        if (data->stats->event->type == sfEvtClosed)
            sfRenderWindow_close(G_WINDOW);
    }
    get_clicks_info(&right, &left, data);
    check_inputs(data, G_ACTUAL_SCENEOBJS->interact, right, left);
}

void audio_engine(game_data_t *data)
{
    music_engine(data, G_AUDIO);
    sfx_engine(data, G_ACTUAL_SCENEOBJS->sfx);
}

void graphic_engine(game_data_t *data)
{
    render_background(data, G_ACTUAL_SCENEOBJS->background);
    get_animations_update(data, G_ACTUAL_SCENEOBJS->render);
    G_ACTUAL_SCENEOBJS->render = mergeSort(G_ACTUAL_SCENEOBJS->render);
    get_render_updates(data, G_ACTUAL_SCENEOBJS->render);
    get_render_updates(data, G_ACTUAL_SCENEOBJS->gui);
    get_texts_updates(data, G_ACTUAL_SCENEOBJS->text);
}

int xfml_game_loop(game_data_t * data)
{
    while (sfRenderWindow_isOpen(G_WINDOW)) {
        input_engine(data);
        sfRenderWindow_clear(G_WINDOW, sfBlack);
        audio_engine(data);
        physics_update(G_ACTUAL_SCENEOBJS->colliders, data);
        get_scripts_updates(data, G_ACTUAL_SCENEOBJS->scripts);
        transform_updates(data, G_ACTUAL_SCENEOBJS->transforms);
        graphic_engine(data);
        sfRenderWindow_display(G_WINDOW);
    }
    return 0;
}