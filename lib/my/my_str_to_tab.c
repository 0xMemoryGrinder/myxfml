/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** copy a string in an other created dynamicly
*/

#include <stdlib.h>

static int count_separators(char const *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == separator)
            count++;
    }
    return count;
}

static char *my_strncpy_cell(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

static int compute_cell_length(char const *str, int idx, char separator)
{
    int length = 0;

    for (int i = idx; str[i] && str[i] != separator; i++, length++);
    return length;
}

char **my_str_to_tab(const char *str, char separator)
{
    int nb_cells = count_separators(str, separator) + 1;
    char **tab = malloc(sizeof(char *) * (nb_cells + 1));
    int sub_idx = 0;
    int cell_length;

    if (tab == NULL)
        return NULL;
    tab[nb_cells] = NULL;
    for (int i = 0; i < nb_cells; i++, sub_idx++) {
        cell_length = compute_cell_length(str, sub_idx, separator);
        tab[i] = malloc(sizeof(char) * (cell_length + 1));
        if (tab[i] == NULL)
            return NULL;
        tab[i] = my_strncpy_cell(tab[i], str + sub_idx, cell_length);
        sub_idx += cell_length;
    }
    return tab;
}