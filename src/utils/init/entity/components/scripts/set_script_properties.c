/*
** EPITECH PROJECT, 2020
** set_script_property.c
** File description:
** set_script_property.c
*/

#include <stdlib.h>
#include "set_script_properties.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/my.h"
#include "../../../../my_puterr.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../common_tags.h"
#include "../../../../../../include/global_tabs.h"

void set_script_toggle(char *content, int *i, script_t *script)
{
    script->toggle = fill_toogle(content, i);
}

void set_script_time_dep(char *content, int *i, script_t *script)
{
    script->time_dependent = fill_toogle(content, i);
}

void set_script_trigger(char *content, int *i, script_t *script)
{
    int path_len = length_of_tag_value(content, *i);
    char *path = my_strndup(content + *i, path_len);
    *i += path_len;

    if (path == NULL)
        my_puterr("Malloc error in strndup", __FILE__, __LINE__);
    script->trigger = my_getnbr(path);
    free(path);
}

void set_script_name(char *content, int *i, script_t *script)
{
    script->name = extract_value(content, i);
}

void set_script_action(char *content, int *i, script_t *script)
{
    script->update = fill_function(content, i, scripts_func_ptr_tab);
}