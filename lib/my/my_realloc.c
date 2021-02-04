/*
** EPITECH PROJECT, 2020
** my_realloc.c
** File description:
** header for my_realloc.c
*/

#include <stdlib.h>

int my_strlen(char *src);
char *my_strcpy(char *, const char *);

char *my_realloc(char *src)
{
    int size = my_strlen(src) + 2;
    char *new = malloc((sizeof(char) * size));

    if (!src) {
        new[0] = 0;
        new[1] = '\0';
    } else {
        my_strcpy(new, src);
        free(src);
        new[size - 1] = '\0';
    }
    return new;
}