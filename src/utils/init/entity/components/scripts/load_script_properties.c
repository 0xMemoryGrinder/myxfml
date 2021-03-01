/*
** EPITECH PROJECT, 2020
** load_script_property.c
** File description:
** load_script_property.c
*/

#include <stdlib.h>
#include "my_xml.h"
#include "my.h"
#include "utils/init/common_tags.h"
#include "global_tabs.h"

int load_script_toggle(xmlnode_t *node, script_t *script)
{
    int status = 1;
    script->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_script_time_dep(xmlnode_t *node, script_t *script)
{
    int status = 1;
    script->time_dependent = xml_toggle("time_dependent", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_script_trigger(xmlnode_t *node, script_t *script)
{
    int status = 1;
    script->trigger = xml_value_int("trigger", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_script_name(xmlnode_t *node, script_t *script)
{
    int status = 1;
    script->name = xml_value_str("name", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_script_action(xmlnode_t *node, script_t *script)
{
    int status = 1;
    char *content = xml_value_str("action", node, &status);

    if (!status)
        return 0;
    script->update = fill_function(content, scripts_func_ptr_tab, &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}