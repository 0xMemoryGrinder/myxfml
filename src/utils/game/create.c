/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** header for create.c
*/

#include <stdlib.h>
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/game.h"
#include "../../../include/types.h"
#include "../my_puterr.h"

game_data_t *malloc_game_data(void)
{
    game_data_t *new = malloc(sizeof(game_data_t));

    if (new == NULL)
        my_puterr("Error malloc game data", __FILE__, __LINE__);
    new->player = NULL;
    new->global_entity = NULL;
    new->gui = NULL;
    new->game_settings = NULL;
    new->stats = NULL;
    new->scenes = NULL;
    return new;
}

game_stats_t *malloc_game_stats(void)
{
    game_stats_t *new = malloc(sizeof(game_stats_t));

    if (new == NULL)
        my_puterr("Error malloc game stats", __FILE__, __LINE__);
    new->time = NULL;
    new->event = NULL;
    new->camera = NULL;
    return new;
}

settings_t *malloc_settings(void)
{
    settings_t *new = malloc(sizeof(settings_t));

    if (new == NULL)
        my_puterr("Error malloc game settings", __FILE__, __LINE__);
    new->video = NULL;
    new->audio = NULL;
    return new;
}