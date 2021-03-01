/*
** EPITECH PROJECT, 2020
** load_scripts_components.c
** File description:
** load_scripts_components.c
*/

#include "utils/init/entity/components/scripts/load_scripts_components.h"
#include "my_xml.h"
#include "my_csfml.h"
#include "my.h"
#include "utils/init/common_tags.h"
#include "my_puterr.h"
#include "global_tabs.h"

int load_scripts_toggle(xmlnode_t *node, script_list_t *scripts)
{
    int status = 1;
    scripts->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_script_destroy(xmlnode_t *node, script_t *script)
{
    int status = 1;
    char *content = xml_value_str("destroy", node, &status);

    if (!status)
        return 0;
    script->destroy = fill_function(content, destroy_sdata_func_ptr_tab,
    &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

script_t *load_script(xmlnode_t *node)
{
    script_t *script = malloc_script_node();

    if (script == NULL || !load_script_name(node, script) ||
    !load_script_action(node, script) || !load_script_destroy(node, script) ||
    !load_script_trigger(node, script))
        return NULL;
    return script;
}

int load_scripts_list(xmlnode_t *node, script_list_t *scripts)
{
    scripts->count = node->children.size;
    script_t *current = NULL;
    script_t *to_check = NULL;

    for (int n = 0; n < node->children.size; n++) {
        if (my_strcmp(node->children.data[n]->tag, "script"))
            return my_puterr("Unknown script tag", __FILE__, __LINE__).nb;
        to_check = load_script(node->children.data[n]);
        if (!to_check)
            return 0;
        if (n == 0) {
            scripts->list = to_check;
            current = scripts->list;
        } else {
            current->next = to_check;
            current = current->next;
        }
    }
    return 1;
}

int load_scripts_component(xmlnode_t *node, components_t *components)
{
    components->scripts = malloc_script_list();

    if (components->scripts == NULL ||
    !load_scripts_toggle(node, components->scripts) ||
    !load_scripts_list(node, components->scripts))
        return 0;
    return 1;
}