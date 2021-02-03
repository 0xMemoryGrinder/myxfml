/*
** EPITECH PROJECT, 2020
** scene.h
** File description:
** header for scene.c
*/

#ifndef LIBCSFML_SCENE_H
#define LIBCSFML_SCENE_H

#include "my_csfml.h"

struct scene_s{
    id sid;
    char *name;
    entity_t *list;
    entity_t *outsight_list;
    int outsight_count;
    action_trigger_t *scene_time;
    int elapsed_time;
    tag_list_t *tags;
    audio_data_t *scene_musics;
    events_action_t *events;
    struct scene_s *paused_scene;
};

#endif //LIBCSFML_SCENE_H
