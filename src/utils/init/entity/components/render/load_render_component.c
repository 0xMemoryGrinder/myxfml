/*
** EPITECH PROJECT, 2020
** load_render_component.c
** File description:
** load_render_component.c
*/

#include "utils/init/entity/components/render/load_render_component_tabs.h"
#include "utils/init/load_file.h"
#include "my.h"
#include "my_csfml.h"
#include "my_puterr.h"
#include "utils/init/common_tags.h"

void load_render_toggle(char *content, int *i, render_sprite_t *render)
{
    render->toggle = fill_toogle(content, i);
}

void load_render_sprite(char *content, int *i, render_sprite_t *render)
{
    char *path = extract_value(content, i);
    render->texture = sfTexture_createFromFile(path, NULL);
    if (render->texture == NULL)
        my_puterr("Error creating texture", __FILE__, __LINE__);
    free(path);
    sfSprite_setTexture(render->sprite, render->texture, sfFalse);
}

void load_render_component(char *content, int *i, components_t *components)
{
    components->render = malloc_rendersprite();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</render>", 9)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (render_conf_tag_action[k].tag && my_strncmp(content + *i,
        render_conf_tag_action[k].tag, render_conf_tag_action[k].tag_len))
            k++;
        if (!render_conf_tag_action[k].tag)
            my_puterr("Unrecognized render tag", __FILE__, __LINE__);
        *i += render_conf_tag_action[k].tag_len;
        render_conf_tag_action[k].action(content, i, components->render);
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
    }
    if (components->render->sprite == NULL)
        my_puterr("Unrecognized sprite", __FILE__, __LINE__);
}