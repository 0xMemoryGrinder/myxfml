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

int scene_scripts_updates(game_data_t *data)
{
    script_t *scripts = G_ACTUAL_SCENE.scene_scripts->list;
    int status = 1;

    if (G_ACTUAL_SCENE.scene_scripts->toggle == OFF)
        return - 1;
    for (; status && scripts; scripts = scripts->next) {
        if (scripts->toggle == OFF)
            continue;
       status = update_script(data, NULL, scripts);
    }
    return status;
}

int graphic_engine(game_data_t *data)
{
    if (!get_animations_update(data, G_ACTUAL_SCENEOBJS->render))
        return 0;
    G_ACTUAL_SCENEOBJS->render = mergeSort(G_ACTUAL_SCENEOBJS->render);
    get_render_updates(data, G_ACTUAL_SCENEOBJS->render);
    get_render_updates(data, G_ACTUAL_SCENEOBJS->gui);
    get_texts_updates(data, G_ACTUAL_SCENEOBJS->text);
    return 1;
}

int xfml_game_loop(game_data_t * data)
{
    while (sfRenderWindow_isOpen(G_WINDOW)) {
        input_engine(data);
        sfRenderWindow_clear(G_WINDOW, sfBlack);
        music_engine(data, G_AUDIO);
        sfx_engine(data, G_ACTUAL_SCENEOBJS->sfx);
        render_background(data, G_ACTUAL_SCENEOBJS->background);
        if (!physics_update(G_ACTUAL_SCENEOBJS->colliders, data)
        || !scene_scripts_updates(data)
        || !get_scripts_updates(data, G_ACTUAL_SCENEOBJS->scripts))
            return 0;
        transform_updates(data, G_ACTUAL_SCENEOBJS->transforms);
        if (!graphic_engine(data))
            return 0;
        sfRenderWindow_display(G_WINDOW);
        kill_entities(data, G_ACTUAL_SCENE.to_free);
    }
    return 1;
}