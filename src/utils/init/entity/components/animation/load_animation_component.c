/*
** EPITECH PROJECT, 2020
** load_animation_component.c
** File description:
** load_animation_component.c
*/

#include "load_animation_component.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../../../include/my.h"
#include "../../../common_tags.h"
#include "../../../../my_puterr.h"



script_t *load_script(char *content, int *i)
{
    script_t *script = malloc_script_node();
    int k;

    skip_to_next_tag(content, i, false);
    while (my_strncmp(content + *i, "</script>", 9)) {
        k = 0;
        while (script_conf_tag_action[k].tag && my_strncmp(content + *i,
        script_conf_tag_action[k].tag, script_conf_tag_action[k].tag_len))
            k++;
        if (!script_conf_tag_action[k].tag)
            my_puterr("Unrecognized script tag", __FILE__, __LINE__);
        *i += script_conf_tag_action[k].tag_len;
        script_conf_tag_action[k].action(content, i, script);
        *i += script_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }
    return script;
}

void load_texts_list(char *content, int *i, script_list_t *scripts)
{
    scripts->count = my_getnbr(content + *i);
    script_t *current = scripts->list;

    skip_to_next_tag(content, i, false);
    for (int n = 0; n < scripts->count; n++, current = current->next) {
        if (n == 0) {
            scripts->list = load_script(content, i);
            current = scripts->list;
        } else
            current = load_script(content, i);
    }
}

void load_animation_component(char *content, int *i, components_t *components)
{
    components->animation = malloc_animations();
    int k;

    skip_to_next_tag(content, i, false);
    while (my_strncmp(content + *i, "</scripts>", 8)) {
        k = 0;
        while (animation_conf_tag_action[k].tag && my_strncmp(content + *i,
        animation_conf_tag_action[k].tag, animation_conf_tag_action[k].tag_len))
            k++;
        if (!animation_conf_tag_action[k].tag)
            my_puterr("Unrecognized scripts tag", __FILE__, __LINE__);
        *i += animation_conf_tag_action[k].tag_len;
        animation_conf_tag_action[k].action(content, i, components->animation);
        *i += animation_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }
}