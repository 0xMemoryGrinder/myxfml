/*
** EPITECH PROJECT, 2020
** background_rendering.c
** File description:
** header for background_rendering.c
*/

#include "my_csfml.h"

void check_animation(game_data_t *data, entity_t *entity)
{
    if (E_ANIMATION == NULL || E_ANIMATION->toggle == OFF)
        return;
    if (E_ANIMATION->actual_anim != E_ANIMATION->actual->name)
        update_anim_state(entity);
    update_anim_frame(data, entity);
}

static void render_it(game_data_t *data, entity_t *entity)
{
    if (E_RSPRITE != NULL && E_RSPRITE->toggle == ON)
        sfRenderWindow_drawSprite(G_WINDOW, E_RSPRITE->sprite, NULL);
}

void render_background(game_data_t *data, entity_t *background)
{
    entity_t *entity = background;

    for (;entity ; entity = entity->next) {
        transform_rendersprite(entity);
        reset_transform(entity);
        check_animation(data, entity);
        render_it(data, entity);
        if (entity->toggle == OFF)
            continue;
        if (entity->children)
            render_background(data, background);
    }
}