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

toggle_t fill_toogle(char *content, int *i)
{
    char *toggle_val = extract_value(content, i);

    if (!my_strcmp(toggle_val, "ON"))
        return ON;
    else if (!my_strcmp(toggle_val, "OFF"))
        return OFF;
    else
        my_puterr("Unknown toggle value", __FILE__, __LINE__);
}

int fill_enum(char *content, int *i, const global_enum_tab_t *tab)
{
    int k = 0;
    int enum_len;
    char *enum_val = NULL;
    //*i += 8; TODO verify necessity
    enum_len = length_of_tag_value(content, *i);
    enum_val = my_strndup(content + *i, enum_len);

    if (enum_val == NULL)
        my_puterr("My_strndup malloc error", __FILE__, __LINE__);
    while (tab[k].str && my_strncmp(enum_val, tab[k].str, tab[k].len))
        k++;
    if (!tab[k].str)
        my_puterr("Unknown enum", __FILE__, __LINE__);
    free(enum_val);
    return tab[k].enum_nb;
}

func_ptr_t fill_function(char *content, int *i,
const global_func_ptr_tab_t *tab)
{
    int k = 0;
    char *func_val = extract_value(content, i);
    while (tab[k].str && my_strncmp(func_val,
    tab[k].str, tab[k].len))
        k++;
    if (!tab[k].str)
        my_puterr("Unknown function", __FILE__, __LINE__);
    free(func_val);
    return tab[k].func_ptr;
}