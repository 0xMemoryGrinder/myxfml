/*
** EPITECH PROJECT, 2020
** core_engine.c
** File description:
** header for core_engine.c
*/
//tppppp
#include <stdio.h>
#include "my_csfml.h"

void start_game(game_data_t *data)
{
    data->stats->click.lclick_time = 0;
    data->stats->click.rclick_time = 0;
    data->stats->click.lclick_trigger = SECONDS(0);
    data->stats->click.rclick_trigger = SECONDS(0);
    if (data->game_settings->video->is_fullscreen)
        G_WINDOW = sfRenderWindow_create(sfVideoMode_getDesktopMode(),
        data->game_settings->video->game_title, sfFullscreen, NULL);
    else
        G_WINDOW = sfRenderWindow_create(data->game_settings->video->mode,
        data->game_settings->video->game_title, sfClose, NULL);
    data->stats->time->game_clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(G_WINDOW, data->game_settings->video->fps);
    data->stats->time->time = 0;
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
    if (data->stats->click.is_lclick || data->stats->click.is_rclick)
        check_inputs(data, G_ACTUAL_SCENEOBJS->gui, &right, &left);
    if (data->stats->click.is_lclick || data->stats->click.is_rclick)
        check_inputs(data, G_ACTUAL_SCENEOBJS->interact, &right, &left);
    data->stats->click.lclick = left;
    data->stats->click.rclick = right;
}

int scene_scripts_updates(game_data_t *data)
{
    script_t *scripts = G_ACTUAL_SCENE.scene_scripts->list;
    int status = 1;

    if (G_ACTUAL_SCENE.scene_scripts->toggle == OFF)
        return -1;
    for (; status && scripts; scripts = scripts->next) {
        if (scripts->toggle == OFF)
            continue;
       status = update_script(data, NULL, scripts);
    }
    return status;
}

static int get_updates(game_data_t *data)
{
    int status1;
    int status2;
    int status3;

    status1 = physics_update(G_ACTUAL_SCENEOBJS->colliders, data);
    if (status1 == 0 || status1 == SCENE_LOADING)
        return status1;
    status2 = scene_scripts_updates(data);
    if (status2 == 0 || status2 == SCENE_LOADING)
        return status2;
    status3 = get_scripts_updates(data, G_ACTUAL_SCENEOBJS->scripts);
    if (status3 == 0 || status3 == SCENE_LOADING)
        return status3;
    return 1;
}

int xfml_game_loop(game_data_t * data)
{
    int status = 1;
    float t = 0;
    float t0 = 0;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(G_WINDOW)) {
        t0 = t;
        t = sfTime_asSeconds(sfClock_getElapsedTime(clock));
        data->stats->time->dt = t - t0;
        if (data->stats->time->dt > 0.15f)
            data->stats->time->dt = 0.15f;
        input_engine(data);
        sfRenderWindow_clear(G_WINDOW, sfBlack);
        music_engine(data, G_AUDIO);
        sfx_engine(data, G_ACTUAL_SCENEOBJS->sfx);
        render_background(data, G_ACTUAL_SCENEOBJS->background);
        status = get_updates(data);
        if (status == 0)
            return 0;
        else if (status == SCENE_LOADING)
            continue;
        transform_updates(data, G_ACTUAL_SCENEOBJS->transforms);
        if (!graphic_engine(data))
            return 0;
        sfRenderWindow_display(G_WINDOW);
        kill_entities(data, G_ACTUAL_SCENE.to_free);
    }
    return 1;
}