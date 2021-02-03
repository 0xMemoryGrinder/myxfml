/*
** EPITECH PROJECT, 2020
** free_entity.c
** File description:
** header for free_entity.c
*/

#include <stdlib.h>
#include "../../my_csfml.h"
#include "../../entity.h"
#include "../../scene.h"
#include "../../base_components.h"
#include "../../struct_shortcuts.h"
#include "../../../include/my.h"

void free_scripts(script_t *scripts)
{
    if (scripts->next)
        free_scripts(scripts->next);
    if (scripts->data)
        free(scripts->data);
    if (scripts != NULL)
        free(scripts);
}

void free_entity(entity_t* entity)
{
    if (entity != NULL) {
        if (E_TRANSFORM)
            free(E_TRANSFORM);
        if (E_COLLIDER)
            free(E_COLLIDER);
        if (E_INTERACT)
            free(E_INTERACT);
        if (E_TEXT)
            free_text(E_TEXT);
        if (E_SOUND)
            free_sound_list(E_SOUND);
        if (E_RSPRITE)
            free_rendersprite(E_RSPRITE);
        if (E_SCRIPT)
            free_scripts(E_SCRIPT);
        if (E_ANIMATION)
            free_animation(E_ANIMATION);
        if (entity->name)
            free(entity->name);
        free(entity);
    }
}

void free_entity_list(entity_t* entity)
{
    if (entity->children)
        free_entity_list(entity->children);
    if (entity->next)
        free_entity_list(entity->next);
    if (entity != NULL)
        free_entity(entity);
}