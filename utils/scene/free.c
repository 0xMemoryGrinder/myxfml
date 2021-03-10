/*
** EPITECH PROJECT, 2020
** free.c
** File description:
** header for free.c
*/

#include <stdlib.h>
#include "my_csfml.h"

void destroy_scene_array(scene_array_t *list, int size)
{
    for (int i = 0; i < size ; i++) {
        list[i].toggle = OFF;
        free(list[i].name);
        free_script_list(list[i].scene_scripts);
        free_entites_list(list[i].objects->interact);
        free_entites_list(list[i].objects->render);
        free_entites_list(list[i].objects->text);
        free_entites_list(list[i].objects->sfx);
        free_entites_list(list[i].objects->colliders);
        free_entites_list(list[i].objects->scripts);
        free_entites_list(list[i].objects->gui);
        free_entites_list(list[i].objects->transforms);
        free_entity_list(list[i].objects->list);
        free_entity_list(list[i].objects->background);
        free(list[i].objects);
    }
    free(list);
}

void destroy_game_scenes(scenes_t *scenes)
{
    destroy_scene_array(scenes->list, scenes->count);
    if (scenes != NULL)
        free(scenes);
}