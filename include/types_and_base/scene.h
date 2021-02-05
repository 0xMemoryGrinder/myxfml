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
    entity_list_t *sfx;
};


struct scene_array_s{
    char *name;
    scene_id id;
    toggle_t toggle;
    scene_objects_t *objects;
    script_t *scene_scripts;
};

struct scenes_s{
    scene_id actual;
    int count;
    scene_array_t *list;
    events_action_t *events;
};


//
//  create scenes
//
scene_array_t *malloc_scene_array(int size);
scenes_t *malloc_scene_struct(void);

#endif //LIBCSFML_SCENE_H
