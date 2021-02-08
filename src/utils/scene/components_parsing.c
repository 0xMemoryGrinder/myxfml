/*
** EPITECH PROJECT, 2020
** components_parsing.c
** File description:
** header for components_parsing.c
*/

#include "../../../include/my_csfml.h"

static void insert_pt2(entity_t *entity, scene_objects_t *objects)
{
    if (E_TEXT)
        add_entity_to_list(entity, &objects->text);
    if (E_SCRIPT)
        add_entity_to_list(entity, &objects->scripts);
    if (E_INTERACT)
        add_entity_to_list(entity, &objects->interact);
}

void insert_entity_inlists(entity_t *entity, scene_objects_t *objects)
{
    if (E_COLLIDER)
        add_entity_to_list(entity, &objects->colliders);
    if (E_RSPRITE)
        add_entity_to_list(entity, &objects->render);
    if (E_SOUND)
        add_entity_to_list(entity, &objects->sfx);
    insert_pt2(entity, objects);
}

void insert_entities_inlists(entity_t *list, scene_objects_t *objects)
{
    entity_t *entity = list;

    for (; entity; entity = entity->next) {
        if (list->children)
            insert_entities_inlists(entity->children, objects);
        insert_entity_inlists(entity, objects);
    }
}

void init_scenes(scenes_t *scenes)
{
    for (int i = 0; i < scenes->count; i++) {
        insert_entities_inlists(scenes->list[i].objects->list,
        scenes->list[i].objects);
    }
}