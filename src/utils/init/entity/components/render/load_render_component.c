/*
** EPITECH PROJECT, 2020
** load_render_component.c
** File description:
** load_render_component.c
*/

#include "my_xml.h"
#include "my.h"
#include "my_csfml.h"
#include "my_puterr.h"

int load_render_toggle(xmlnode_t *node, render_sprite_t *render)
{
    int status = 1;
    render->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_render_sprite(xmlnode_t *node, render_sprite_t *render)
{
    int status = 1;
    char *path = xml_value_str("path", node, &status);

    if (!status)
        return 0;
    render->texture = sfTexture_createFromFile(path, NULL);
    if (render->texture == NULL)
        return my_puterr("Error creating texture", __FILE__, __LINE__).nb;
    free(path);
    sfSprite_setTexture(render->sprite, render->texture, sfFalse);
    return 1;
}

int load_render_component(xmlnode_t *node, components_t *components)
{
    components->render = malloc_rendersprite();

    if (components->render == NULL ||
    !load_render_toggle(node, components->render) ||
    !load_render_sprite(node, components->render))
        return 0;
    return 1;
}