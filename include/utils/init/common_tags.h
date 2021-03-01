/*
** EPITECH PROJECT, 2020
** common_tags.h
** File description:
** header for common_tags.c
*/

#ifndef LIB_MYCSFML_COMMON_TAGS_H
#define LIB_MYCSFML_COMMON_TAGS_H

#include "global_tabs.h"
#include "my_csfml.h"

int fill_enum(char *value, const global_enum_tab_t *tab, int *status);

typedef void *(*func_ptr_t)();
func_ptr_t fill_function(char *value, const global_func_ptr_tab_t *tab,
int *status);

#endif //LIB_MYCSFML_COMMON_TAGS_H
