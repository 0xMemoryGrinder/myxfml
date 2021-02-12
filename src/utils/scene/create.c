/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** header for create.c
*/

#include <stdlib.h>
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types.h"
#include "my_puterr.h"


scene_objects_t *malloc_scene_objects(void)
{
    scene_objects_t *new = malloc(sizeof(scene_objects_t));

    if (new == NULL)
        my_puterr("Error : malloc scene entity_templates", __FILE__, __LINE__);
    new->list = NULL;
    new->interact = NULL;
    new->render = NULL;
    new->text = NULL;
    new->sfx = NULL;
    new->scripts = NULL;
    new->colliders = NULL;
    return new;
}

scene_array_t *malloc_scene_array(int size)
{
    scene_array_t *new = malloc(sizeof(scene_array_t) * (size));

    if (new == NULL)
        my_puterr("Error : malloc scene array", __FILE__, __LINE__);
    for (int i = 0; i < size; i++) {
        new[i].toggle = ON;
        new[i].name = NULL;
        new[i].id = i;
        new[i].objects = malloc_scene_objects();
        new[i].scene_scripts = NULL;
    }
    return new;
}

scenes_t *malloc_scene_struct(void)
{
    scenes_t *new = malloc(sizeof(scenes_t));

    if (new == NULL)
        my_puterr("Error : malloc scenes structure", __FILE__, __LINE__);
    new->count = 0;
    new->actual = 0;
    new->list = NULL;
    return new;
}