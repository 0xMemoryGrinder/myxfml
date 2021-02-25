/*
** EPITECH PROJECT, 2020
** scene.h
** File description:
** header for scene.c
*/

#ifndef LIBCSFML_SCENE_H
#define LIBCSFML_SCENE_H

#include "../types.h"
#include "custom_structs.h"

struct scene_objects_s {
    entity_t *list;
    entity_t *background;
    entity_list_t *colliders;
    entity_list_t *render;
    entity_list_t *scripts;
    entity_list_t *interact;
    entity_list_t *text;
    entity_list_t *sfx;
    entity_list_t *transforms;
    entity_list_t *gui;
};

struct scene_array_s{
    char *name;
    scene_id id;
    toggle_t toggle;
    scene_objects_t *objects;
    script_list_t *scene_scripts;
};

struct scenes_s{
    scene_id actual;

    int count;
    scene_array_t *list;
};


//
//  create scenes
//
scene_array_t *malloc_scene_array(int size);
scenes_t *malloc_scene_struct(void);



//
//  destroy game scene
//
void destroy_game_scenes(scenes_t *scenes);


//
//  SCENE UTILS
//
void insert_entities_inlists(entity_t *list, scene_objects_t *objects
, sfBool is_gui);
void insert_entity_inlists(entity_t *entity, scene_objects_t *objects
, sfBool is_gui);

#endif //LIBCSFML_SCENE_H
