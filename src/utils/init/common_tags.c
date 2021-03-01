/*
** EPITECH PROJECT, 2020
** common_tags.c
** File description:
** common_tags.c
*/

#include <stdlib.h>
#include "../../../include/my_csfml.h"
#include "../../../include/utils/init/common_tags.h"
#include "../../../include/utils/init/load_file.h"
#include "../../../include/my.h"
#include "my_puterr.h"
#include "../../../include/global_tabs.h"

int fill_enum(char *value, const global_enum_tab_t *tab, int *status)
{
    int k = 0;

    while (tab[k].str && my_strcmp(value, tab[k].str))
        k++;
    if (!tab[k].str) {
        *status = my_puterr("Unknown enum", __FILE__, __LINE__).nb;
        return 0;
    }
    return tab[k].enum_nb;
}

func_ptr_t fill_function(char *value, const global_func_ptr_tab_t *tab,
int *status)
{
    int k = 0;

    while (tab[k].str && my_strcmp(value, tab[k].str))
        k++;
    if (!tab[k].str) {
        *status = my_puterr("Unknown function", __FILE__, __LINE__).nb;
        return NULL;
    }
    return tab[k].func_ptr;
}