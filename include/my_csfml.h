/*
** EPITECH PROJECT, 2020
** my_csfml.h
** File description:
** header for my_csfml.c
*/

#ifndef LIBCSFML_MY_CSFML_H
#define LIBCSFML_MY_CSFML_H

#include "types_and_base/entity.h"
#include "types_and_base/events.h"
#include "types_and_base/clock.h"
#include "types_and_base/base_components.h"
#include "types_and_base/game.h"
#include "types_and_base/video.h"
#include "types_and_base/music.h"
#include "types_and_base/struct_shortcuts.h"
#include "types_and_base/scene.h"

#include "audio_engine/audio_engine.h"
#include "scripts_engine/script_updates.h"
#include "physics_engine/physics.h"
#include "graphic_engine/render_fonctions.h"
#include "input_engine/input_engine.h"


int xfml_game_loop(game_data_t * data);
void start_game(game_data_t *data);

#include "utils/components_utils.h"
#include "utils/converter.h"

#endif //LIBCSFML_MY_CSFML_H
