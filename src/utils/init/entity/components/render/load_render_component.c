/*
** EPITECH PROJECT, 2020
** load_render_component.c
** File description:
** load_render_component.c
*/

#include "load_render_component.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../../../include/my.h"
#include "../../../../../../include/my_csfml.h"
#include "../../../../my_puterr.h"
#include "../../../common_tags.h"

void load_render_toggle(char *content, int *i, render_sprite_t *render)
{
    render->toggle = fill_toogle(content, i);
}

void load_render_sprite(char *content, int *i, render_sprite_t *render)
{
    char *path = extract_value(content, i);
    render->texture = sfTexture_createFromFile(path, NULL);
    free(path);
}

void load_render_component(char *content, int *i, components_t *components)
{
    components->render = malloc_rendersprite();
    int k;

    skip_to_next_tag(content, i, false);
    while (my_strncmp(content + *i, "</render>", 9)) {
        k = 0;
        while (render_conf_tag_action[k].tag && my_strncmp(content + *i,
        render_conf_tag_action[k].tag, render_conf_tag_action[k].tag_len))
            k++;
        if (!render_conf_tag_action[k].tag)
            my_puterr("Unrecognized sounds tag", __FILE__, __LINE__);
        *i += render_conf_tag_action[k].tag_len;
        render_conf_tag_action[k].action(content, i, components->sounds);
        *i += render_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }
    if (components->render->sprite == NULL)
        my_puterr("Unrecognized sprite", __FILE__, __LINE__);
}