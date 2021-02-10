/*
** EPITECH PROJECT, 2020
** entity_loader.h
** File description:
** header for entity_loader.c
*/

#ifndef LIB_MYCSFML_LOAD_ENTITY_H
#define LIB_MYCSFML_LOAD_ENTITY_H

#include "../conf_tag_action_struct.h"
#include "set_entity_properties.h"
#include "components/load_components.h"

static struct conf_tag_action_s entity_conf_tag_action[] = {
        {"<name>", 6, (void *(*)()) &set_entity_name},
        {"<type>", 6, (void *(*)()) &set_entity_type},
        {"<toggle>", 8, (void *(*)()) &set_entity_toggle},
        {"<components>", 12, (void *(*)()) &load_components},
        {NULL, 0, NULL}
        //{"components", 10, &load_components},

};

#endif //LIB_MYCSFML_LOAD_ENTITY_H
