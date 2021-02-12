/*
** EPITECH PROJECT, 2020
** load_interactive_component.c
** File description:
** load_interactive_component.c
*/

#include "load_interactive_component.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/utils/init_xfml.h"
#include "../../../../../../include/my.h"
#include "../../../../../../include/my_puterr.h"
#include "utils/init/common_tags.h"

void load_interact_toggle(char *content, int *i, interact_t *interact)
{
    interact->toggle = fill_toogle(content, i);
}

void load_interact_left_click(char *content, int *i, interact_t *interact)
{
    interact->click_left = fill_toogle(content, i);
}

void load_interact_right_click(char *content, int *i, interact_t *interact)
{
    interact->click_right = fill_toogle(content, i);
}

void load_interactive_component(char *content, int *i, components_t *components)
{
    components->interact = malloc_interact();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</interactive>", 14)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (interact_conf_tag_action[k].tag && my_strncmp(content + *i,
        interact_conf_tag_action[k].tag, interact_conf_tag_action[k].tag_len))
            k++;
        if (!interact_conf_tag_action[k].tag)
            my_puterr("Unrecognized interactive tag", __FILE__, __LINE__);
        *i += interact_conf_tag_action[k].tag_len;
        interact_conf_tag_action[k].action(content, i, components->interact);
        *i += interact_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}