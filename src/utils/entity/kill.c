/*
** EPITECH PROJECT, 2020
** kill.c
** File description:
** header for kill.c
*/

#include "my_csfml.h"

void kill_entity_pt2(entity_t *entity, scene_objects_t *objects)
{
    if (E_SOUND)
        pop_entity_fromlist(entity, &objects->sfx);
    if (E_TEXT)
        pop_entity_fromlist(entity, &objects->text);
    if (E_INTERACT)
        pop_entity_fromlist(entity, &objects->interact);

}

void kill_entity(entity_t *entity, scene_objects_t *objects)
{
    if (E_RSPRITE || E_TRANSFORM || E_COLLIDER) {
        if (E_RSPRITE)
            pop_entity_fromlist(entity, &objects->render);
        if (E_TRANSFORM)
            pop_entity_fromlist(entity, &objects->transforms);
        if (E_COLLIDER)
            pop_entity_fromlist(entity, &objects->colliders);
    } if (E_SCRIPT)
        pop_entity_fromlist(entity, &objects->scripts);
}
