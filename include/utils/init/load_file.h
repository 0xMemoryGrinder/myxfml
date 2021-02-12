/*
** EPITECH PROJECT, 2020
** load_file.h
** File description:
** header for load_file.c
*/

#ifndef LIB_MYCSFML_LOAD_FILE_H
#define LIB_MYCSFML_LOAD_FILE_H

#include <stdbool.h>


typedef enum {
    OPEN, CLOSE, NEXT
} next_tag_type_t;

char *load_file(char *filepath);
void skip_to_next_tag(char const *content, int *i, next_tag_type_t type);
int length_of_tag_value(char *content, int i);
char *extract_value(char *content, int *i);

#endif //LIB_MYCSFML_LOAD_FILE_H
