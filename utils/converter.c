/*
** EPITECH PROJECT, 2020
** converter.c
** File description:
** header for converter.c
*/

#include "types.h"
#include "my.h"
#include "my_xml.h"
#include <stdarg.h>

sfIntRect get_rect(sfVector2f pos, sfVector2f dim,
sfVector2f ant)
{
    sfIntRect r;
    r.left = (int)pos.x + (int)ant.x;
    r.top = (int)pos.y + (int)ant.y;
    r.height = (int)dim.y;
    r.width = (int)dim.x;
    return r;
}

int str_single_cat(char *new, const char *actual, int str_size, int *new_idx)
{
    for (int k = 0; k < str_size; k++, *new_idx += 1)
        new[*new_idx] = actual[k];
    new[*new_idx] = '\0';
    return str_size;
}

char *my_multiple_strcat(int n, ...)
{
    int str_size;
    int actual_size = 0;
    int new_idx = 0;
    char *actual;
    char *new = NULL;
    va_list strings;

    va_start(strings, n);
    for (int i = 0; i < n; i++) {
        actual = va_arg(strings, char *);
        if (actual == NULL)
            return NULL;
        str_size = my_strlen(actual);
        new = mem_expand(new, sizeof(char) * actual_size,
       sizeof(char) * (actual_size + str_size + 1));
        if (new == NULL)
            return NULL;
        actual_size += str_single_cat(new, actual, str_size, &new_idx);
    } va_end(strings);
    return new;
}

void free_multiple_ptr(int n, ...)
{
    va_list list;
    va_start(list, n);
    void *data;

    for (int i = 0; i < n; i++) {
        data = va_arg(list, void *);
        if (data)
            free(data);
    }
    va_end(list);
}