/*
** EPITECH PROJECT, 2020
** create_pt2.c
** File description:
** header for create_pt2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_csfml.h"
#include "my_puterr.h"

render_sprite_t *malloc_rendersprite(void)
{
    render_sprite_t *render = malloc(sizeof(render_sprite_t));

    if (render == NULL)
        return my_puterr("Malloc error rendersprite structure",
        __FILE__, __LINE__).ptr;
    render->texture = NULL;
    render->sprite = sfSprite_create();
    render->toggle = OFF;
    return render;
}

transform_t *malloc_transform(void)
{
    transform_t *transform = malloc(sizeof(transform_t));

    if (transform == NULL)
        return my_puterr("Error : malloc transform structure",
        __FILE__, __LINE__).ptr;
    transform->velocity = (sfVector2f){0, 0};
    transform->position = (sfVector2f){0, 0};
    transform->scale = (sfVector2f){1, 1};
    transform->speed = 0;
    transform->rotation = 0;
    return transform;
}

script_list_t *malloc_script_list(void)
{
    script_list_t *list = malloc(sizeof (script_list_t));

    if (list == NULL)
        return my_puterr("Error : malloc script list structure",
        __FILE__, __LINE__).ptr;
    list->toggle = OFF;
    list->count = 0;
    list->list = NULL;
    return list;
}

script_t *malloc_script_node(void)
{
    script_t *script = malloc(sizeof(script_t));

    if (script == NULL)
        return my_puterr("Error : malloc script node",
        __FILE__, __LINE__).ptr;
    script->toggle = OFF;
    script->time_dependent = OFF;
    script->data = NULL;
    script->name = NULL;
    script->next = NULL;
    script->update = NULL;
    script->destroy = NULL;
    script->actual = 0;
    script->trigger = 0;
    return script;
}

interact_t *malloc_interact(void)
{
    interact_t *new = malloc(sizeof(interact_t));

    if (new == NULL)
        return my_puterr("Error : malloc interact structure",
        __FILE__, __LINE__).ptr;
    new->click_left = OFF;
    new->click_right = OFF;
    new->is_lclick = OFF;
    new->is_rclick = OFF;
    new->toggle = OFF;
    new->lclick = (sfVector2f){0, 0};
    new->rclick = (sfVector2f){0, 0};
    return new;
}