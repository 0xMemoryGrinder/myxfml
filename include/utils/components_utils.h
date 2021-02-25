/*
** EPITECH PROJECT, 2020
** components_utils.h
** File description:
** header for components_utils.c
*/

#ifndef MY_DEFENDER_COMPONENTS_UTILS_H
#define MY_DEFENDER_COMPONENTS_UTILS_H

#include "types.h"


void toggle_collider_fromlist(entity_t *list, char *name, toggle_t toggle);
void toggle_rendersprite_fromlist(entity_t *list, char *name, toggle_t toggle);
void toggle_transform_fromlist(entity_t *list, char *name, toggle_t toggle);

// SCRIPTS
script_t *get_script_fromactual(entity_t *entity, char *name);
script_t *get_script_fromlist(entity_t *list, char *ename, char *sname);
void toggle_script_fromactual(entity_t *entity, char *sname, toggle_t toggle);
void toggle_script_fromlist(entity_t *list, char *ename,
char *sname ,toggle_t toggle);
void *get_script_data_fromlist(entity_t *entity,
char *ename, char *sname);
void *get_script_data_fromactual(entity_t *entity, char *sname);

// TEXT
int get_text_idx_fromactual(entity_t *entity, char *id);
void toggle_text_fromactual(entity_t *entity, char *id, toggle_t toggle);
void toggle_text_fromlist(entity_t *list, char *ename,
char *id, toggle_t toggle);
void toggle_textlist_fromlist(entity_t *list, char *name, toggle_t toggle);

//SFX
void toggle_sfxlist_fromlist(entity_t *list, char *name, toggle_t toggle);
void toggle_sfx_fromactual(entity_t *entity, char *sname, toggle_t toggle);
void toggle_sfx_fromlist(entity_t *list, char *ename,
char *sname, toggle_t toggle);



#endif //MY_DEFENDER_COMPONENTS_UTILS_H
