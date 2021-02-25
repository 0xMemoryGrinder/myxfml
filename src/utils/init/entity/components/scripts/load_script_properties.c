/*
** EPITECH PROJECT, 2020
** load_script_property.c
** File description:
** load_script_property.c
*/

#include <stdlib.h>
#include "my_csfml.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init/load_file.h"
#include "utils/init/common_tags.h"
#include "global_tabs.h"

void load_script_toggle(char *content, int *i, script_t *script)
{
    script->toggle = fill_toogle(content, i);
}

void load_script_time_dep(char *content, int *i, script_t *script)
{
    script->time_dependent = fill_toogle(content, i);
}

void load_script_trigger(char *content, int *i, script_t *script)
{
    int path_len = length_of_tag_value(content, *i);
    char *path = my_strndup(content + *i, path_len);
    *i += path_len;

    if (path == NULL)
        my_puterr("Malloc error in strndup", __FILE__, __LINE__);
    script->trigger = my_getnbr(path);
    free(path);
}

void load_script_name(char *content, int *i, script_t *script)
{
    script->name = extract_value(content, i);
}

void load_script_action(char *content, int *i, script_t *script)
{
    script->update = fill_function(content, i, scripts_func_ptr_tab);
}