/*
** EPITECH PROJECT, 2020
** my_strndup.c
** File description:
** my_strndup.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strndup(char *str, int n)
{
    char *new = malloc(sizeof(char) * (n + 1));

    if (new == NULL)
        return NULL;
    my_strncpy(new, str, n);
    return new;
}