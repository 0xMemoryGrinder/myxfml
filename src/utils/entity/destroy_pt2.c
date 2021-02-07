/*
** EPITECH PROJECT, 2020
** destroy_pt2.c
** File description:
** header for destroy_pt2.c
*/

#include <stdlib.h>
#include "../../../include/my_csfml.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/struct_shortcuts.h"
#include "../../../include/my.h"

void kill_entity(entity_t *entity, scene_objects_t *objects)
{
    pop_entity_fromlist(entity, &objects->scripts);
    pop_entity_fromlist(entity, &objects->colliders);
    pop_entity_fromlist(entity, &objects->sfx);
    pop_entity_fromlist(entity, &objects->text);
    pop_entity_fromlist(entity, &objects->render);
    pop_entity_fromlist(entity, &objects->interact);
    remove_entity(entity);
}