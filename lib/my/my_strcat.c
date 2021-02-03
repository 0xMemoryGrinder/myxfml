/*
** EPITECH PROJECT, 2020
** MY_STRCAT.C
** File description:
** concat two string
*/

#include <stdlib.h>

int my_strlen_cat(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char *my_strcat(char *dest , char  const *src)
{
    int dest_length = my_strlen_cat(dest);
    int src_lenght = my_strlen_cat(src);
    char *new_str = malloc(sizeof(char) * (dest_length + src_lenght + 1));
    int i = 0;
    int new_i;

    for (; dest[i] != '\0'; new_str[i] = dest[i], i++);
    new_i = i;
    for (i = 0; src[i] != '\0'; new_str[new_i] = src[i], new_i++, i++);
    new_str[new_i] = '\0';
    return new_str;
}