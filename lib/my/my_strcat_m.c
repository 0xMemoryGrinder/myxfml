/*
** EPITECH PROJECT, 2020
** my_strcat_m.c
** File description:
** my_strcat_m.c
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);

char *my_strcat_m(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    char *new_str = malloc(sizeof(char) * (len1 + len2 + 1));
    new_str[0] = '\0';
    new_str = my_strcat(new_str, s1);
    new_str = my_strcat(new_str, s2);

    return new_str;
}