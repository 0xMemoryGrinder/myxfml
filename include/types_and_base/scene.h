/*
** EPITECH PROJECT, 2020
** scene.h
** File description:
** header for scene.c
*/

#ifndef LIBCSFML_SCENE_H
#define LIBCSFML_SCENE_H

#include "../my_csfml.h"


struct scene_objects_s{
    entity_t *list;
    entity_list_t *colliders;
    entity_list_t *render;
    entity_list_t *scripts;
    entity_list_t *interact;
    entity_list_t *text;
};


struct scene_s{
    char *name;
    scene_objects_t *objects;
    events_action_t *events;
    struct scene_s *paused_scene;
};

#endif //LIBCSFML_SCENE_H
