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
//  FROM : COLLIDER
#define C_COLLIDER collider->components->collider
#define C_RSPRITE collider->components->render
#define C_TRANSFORM collider->components->transform
#define C_SOUND collider->components->sounds
#define C_TEXT collider->components->texts
#define C_INTERACT collider->components->interact
#define C_SCRIPT collider->components->scripts
#define C_ANIMATION collider->components->animation

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
#define G_SCENE data->scene
#define G_PAUSE_SCENE data->scene->paused_scene
#define G_WINDOW data->game_settings->video->window

#define onCollision() on_collision(self, collider, data)

#endif //LIBCSFML_STRUCT_SHORTCUTS_H
