/*
** EPITECH PROJECT, 2020
** load_components.h
** File description:
** header for load_components.c
*/

#ifndef LIB_MYCSFML_LOAD_COMPONENTS_H
#define LIB_MYCSFML_LOAD_COMPONENTS_H

#include "../../conf_tag_action_struct.h"
#include "../load_entity_properties.h"
#include <stdlib.h>

int load_texts_component(xmlnode_t *node, components_t *components);
int load_sounds_component(xmlnode_t *node, components_t *components);
int load_render_component(xmlnode_t *node, components_t *components);
int load_transform_component(xmlnode_t *node, components_t *components);
int load_scripts_component(xmlnode_t *node, components_t *components);
int load_collider_component(xmlnode_t *node, components_t *components);
int load_interactive_component(xmlnode_t *node, components_t *components);
int load_animation_component(xmlnode_t *node, components_t *components);

static const struct conf_tag_action_s components_conf_tag_action[] = {
        {"texts", &load_texts_component},
        {"sounds", &load_sounds_component},
        {"render", &load_render_component},
        {"transform", &load_transform_component},
        {"scripts", &load_scripts_component},
        {"collider", &load_collider_component},
        {"interactive", &load_interactive_component},
        {"animation", &load_animation_component},
        {NULL, NULL}

};

int load_components(xmlnode_t *node, entity_t *entity);

#endif //LIB_MYCSFML_LOAD_COMPONENTS_H
