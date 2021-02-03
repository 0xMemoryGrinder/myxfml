/*
** EPITECH PROJECT, 2020
** entity.h
** File description:
** header for entity.c
*/

#ifndef LIBCSFML_ENTITY_H
#define LIBCSFML_ENTITY_H

#include "my_csfml.h"

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
    script_t *scripts;
};

struct entity_s{
    char *name;
    id type;
    components_t *components;
    entity_t *children;
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


//
//  Utils Entity
//
void add_entity(entity_t *entity, entity_t **list);
void add_entity_to_list(entity_t *entity, entity_list_t **list);
void remove_entity(entity_t *entity);
void remove_entity_fromlist(entity_list_t *entity);



//
//  free components
//
void free_scripts(script_t *scripts);
void free_text(texts_t *texts);
void free_rendersprite(render_sprite_t *render);
void free_sound_list(sfx_list_t *sounds);
void free_anim_list(anim_t *animation);
void free_animation(animation_t *animation);

#endif //LIBCSFML_ENTITY_H
