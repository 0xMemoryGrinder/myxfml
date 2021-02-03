/*
** EPITECH PROJECT, 2020
** evil
** File description:
** 666
*/

#include <stddef.h>
#include <stdlib.h>

char *my_revstr(char *str)
{
    int size = 0;
    int rev_size = 0;
    int i = 0;
    char *new_str = NULL;

    while (str[size] != '\0')
        size++;
    new_str = malloc(sizeof(char) * size);
    rev_size = (size -1);
    for (; i < size ; i++, rev_size--)
        new_str[i] = str[rev_size];
    new_str[i] = '\0';
    return (new_str);
}