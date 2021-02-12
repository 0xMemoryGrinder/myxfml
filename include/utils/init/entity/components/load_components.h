/*
** EPITECH PROJECT, 2020
** load_components.h
** File description:
** header for load_components.c
*/

#ifndef LIB_MYCSFML_LOAD_COMPONENTS_H
#define LIB_MYCSFML_LOAD_COMPONENTS_H

#include "../../conf_tag_action_struct.h"
#include "../set_entity_properties.h"
#include <stdlib.h>

void load_texts_component(char *content, int *i, components_t *components);
void load_sounds_component(char *content, int *i, components_t *components);
void load_render_component(char *content, int *i, components_t *components);
void load_transform_component(char *content, int *i, components_t *components);
void load_scripts_component(char *content, int *i, components_t *components);
void load_collider_component(char *content, int *i, components_t *components);
void load_interactive_component(char *content, int *i, components_t *components);
void load_animation_component(char *content, int *i, components_t *components);

static const struct conf_tag_action_s components_conf_tag_action[] = {
        {"<texts>", 7, (void *(*)()) &load_texts_component},
        {"<sounds>", 8, (void *(*)()) &load_sounds_component},
        {"<render>", 8, (void *(*)()) &load_render_component},
        {"<transform>", 11, (void *(*)()) &load_transform_component},
        {"<scripts>", 9, (void *(*)()) &load_scripts_component},
        {"<collider>", 10, (void *(*)()) &load_collider_component},
        {"<interactive>", 13, (void *(*)()) &load_interactive_component},
        {"<animation>", 11, (void *(*)()) &load_animation_component},
        {NULL, 0, NULL}

};

void load_components(char *content, int *i, entity_t *entity);

#endif //LIB_MYCSFML_LOAD_COMPONENTS_H
