/*
** EPITECH PROJECT, 2020
** entity.h
** File description:
** header for entity.c
*/

#ifndef LIBCSFML_ENTITY_H
#define LIBCSFML_ENTITY_H

#include "../types.h"
#include "../custom_structs.h"

//
// entity test
//
struct components_s{
    transform_t *transform;
    texts_t *texts;
    sfx_list_t *sounds;
    render_sprite_t *render;
    collider_t *collider;
    animation_t *animation;
    interact_t *interact;
    script_list_t *scripts;
};

struct dependencies_s{
   sfBool collider;
   sfBool render;
   sfBool script;
   sfBool interact;
   sfBool text;
   sfBool sfx;
};

struct entity_s{
    char *name;
    toggle_t toggle;
    entity_id type;
    dependent_t is_in;
    components_t *components;
    char *path;
    entity_t *children;
    void *(*on_destroy)();
    entity_t *parent;
    entity_t *next;
    entity_t *back;
};

struct entity_list_s{
    entity_t *entity;
    entity_list_t *next;
    entity_list_t *back;
};



//
//  Free entity
//
void free_entity(entity_t *entity);
void free_entity_list(entity_t* entity);
void free_entites_list(entity_list_t *entity);


//
//  Alloc entity
//
entity_t *malloc_entity_node(void);
entity_list_t *malloc_list_node(void);

//
//  Sort entity_list_t
//
entity_list_t *mergeSort(entity_list_t *head);



//
//  Utils Entity
//
void add_entity(entity_t *entity, entity_t **list);
void add_entity_children(entity_t *entity, entity_t **list);
void add_entity_to_list(entity_t *entity, entity_list_t **list);
void remove_entity(entity_t *entity);
entity_t *pop_actual_fromlist(entity_list_t **entity);
void remove_actual_fromlist(entity_list_t **entity);
void swap_actual_tolist(entity_list_t **from, entity_list_t **to);
entity_t *pop_entity_fromlist(entity_t *entity, entity_list_t **list);
entity_t *get_entity_name(entity_t *entity, const char *name);
void kill_entity(entity_t *entity, scene_objects_t *objects);

#endif //LIBCSFML_ENTITY_H
