/*
** EPITECH PROJECT, 2020
** init_xfml.h
** File description:
** header for init_xfml.c
*/

#ifndef LIBCSFML_INIT_XFML_H
#define LIBCSFML_INIT_XFML_H


#include "my_xml.h"
#include "init/load_file.h"
#include "init/conf_tag_action_struct.h"
#include "init/common_tags.h"

#include "init/entity/load_entity.h"
#include "init/entity/load_entity_properties.h"


#include "init/entity/components/load_components.h"

#include "init/entity/components/texts/load_texts_component.h"


entity_t *load_entity(char *filepath, entity_t *parent);
int mod_toggle(xmlnode_t *node, toggle_t *toggle, char *key);
int mod_int_value(xmlnode_t *node, int *data, char *key);
int mod_float_value(xmlnode_t *node, float *data, char *key);
int mod_str(xmlnode_t *node, char **str, char *key);
int moddify_entity(xmlnode_t *node, entity_t *entity);

typedef struct tag_ftc_s {
    char *tag;
    void *(*func)();
} tag_ftc_t;

#define ftc (void *(*)())

char *get_entity_path(xmlnode_t *node, char *scene_name);
int load_global_entities(xmlnode_t *node, game_data_t *data);
int load_scene(char *path, scene_id id, game_data_t *data);
int insert_globals(xmlnode_t *node, game_data_t *data, scene_array_t *scene);
game_data_t *create_game(void);

#endif //LIBCSFML_INIT_XFML_H
