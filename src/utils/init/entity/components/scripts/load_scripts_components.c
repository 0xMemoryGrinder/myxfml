/*
** EPITECH PROJECT, 2020
** load_scripts_components.c
** File description:
** load_scripts_components.c
*/

#include "load_scripts_components.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../../../include/my.h"
#include "../../../../../../include/utils/init/common_tags.h"
#include "my_puterr.h"
#include "set_script_properties.h"

void set_scripts_toggle(char *content, int *i, script_list_t *scripts)
{
    scripts->toggle = fill_toogle(content, i);
}

script_t *load_script(char *content, int *i)
{
    script_t *script = malloc_script_node();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</script>", 9)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (script_conf_tag_action[k].tag && my_strncmp(content + *i,
        script_conf_tag_action[k].tag, script_conf_tag_action[k].tag_len))
            k++;
        if (!script_conf_tag_action[k].tag)
            my_puterr("Unrecognized script tag", __FILE__, __LINE__);
        *i += script_conf_tag_action[k].tag_len;
        script_conf_tag_action[k].action(content, i, script);
        *i += script_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
    return script;
}

void load_scripts_list(char *content, int *i, script_list_t *scripts)
{
    scripts->count = my_getnbr(content + *i);
    script_t *current = scripts->list;

    for (int n = 0; n < scripts->count; n++) {
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
        *i += 1;
        skip_to_next_tag(content, i, OPEN);
        if (n == 0) {
            scripts->list = load_script(content, i);
            current = scripts->list;
        } else {
            current->next = load_script(content, i);
            current = current->next;
        }
        skip_to_next_tag(content, i, CLOSE);
    }
    *i += 1;
    skip_to_next_tag(content, i, CLOSE);
}

void load_scripts_component(char *content, int *i, components_t *components)
{
    components->scripts = malloc_script_list();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</scripts>", 8)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (scripts_conf_tag_action[k].tag && my_strncmp(content + *i,
        scripts_conf_tag_action[k].tag, scripts_conf_tag_action[k].tag_len))
            k++;
        if (!scripts_conf_tag_action[k].tag)
            my_puterr("Unrecognized scripts tag", __FILE__, __LINE__);
        *i += scripts_conf_tag_action[k].tag_len;
        scripts_conf_tag_action[k].action(content, i, components->scripts);
        *i += scripts_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}