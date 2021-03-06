/*
** EPITECH PROJECT, 2020
** struct_shortcuts.h
** File description:
** header for struct_shortcuts.c
*/

#ifndef LIBCSFML_STRUCT_SHORTCUTS_H
#define LIBCSFML_STRUCT_SHORTCUTS_H

//
//  Components Shortcuts
//

//  FROM : ENTITY
#define E_COLLIDER entity->components->collider
#define E_RSPRITE entity->components->render
#define E_TRANSFORM entity->components->transform
#define E_SOUND entity->components->sounds
#define E_TEXT entity->components->texts
#define E_INTERACT entity->components->interact
#define E_SCRIPT entity->components->scripts
#define E_ANIMATION entity->components->animation
//  FROM : COMPONENTS
#define C_COLLIDER components->collider
#define C_RSPRITE components->render
#define C_TRANSFORM components->transform
#define C_SOUND components->sounds
#define C_TEXT components->texts
#define C_INTERACT components->interact
#define C_SCRIPT components->scripts
#define C_ANIMATION components->animation

//
//  Animation component
//
//  FROM : ANIMATION
#define ACTUAL_FRAME E_ANIMATION->actual_frame
#define A_CROP E_ANIMATION->actual->frame
#define ACTUAL_CROP E_ANIMATION->actual->frame[ACTUAL_FRAME]



//
//  Entity List Shortcuts
//

//  FROM : DATA
#define GE_GLOBAL data->global_entity
#define GE_SCENE data->scene->entity_list
#define GE_PLAYER data->player
#define GE_GUI data->player



//
//  Main shortcuts
//
#define G_WINDOW data->game_settings->video->window

//  CAMERA
#define G_VIEW data->stats->camera->camera
#define G_CAMERA data->stats->camera


//  CLOCK
#define G_CLOCK data->stats->time


//  AUDIO
#define G_AUDIO data->game_settings->audio
#define G_SFXV data->game_settings->audio->sfx_volume
#define G_MUSCIV data->game_settings->audio->music_volume


// SCENE
#define G_ACTUAL_SCENE data->scenes->list[data->scenes->actual]
#define G_ACTUAL_SCENEOBJS data->scenes->list[data->scenes->actual].objects

#endif //LIBCSFML_STRUCT_SHORTCUTS_H
