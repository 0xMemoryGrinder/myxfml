/*
** EPITECH PROJECT, 2020
** input_engine.c
** File description:
** header for input_engine.c
*/

#include "my_csfml.h"

sfVector2f get_cursor_pos(game_data_t *data)
{
    sfVector2f rcursor = {0, 0};
    sfVector2i cursor = sfMouse_getPositionRenderWindow(G_WINDOW);
    sfVector2u wsize = sfRenderWindow_getSize(G_WINDOW);
    sfVector2f view_size = sfView_getSize(G_VIEW);
    float xscale = (float)wsize.x / view_size.x;
    float yscale = (float)wsize.y / view_size.y;

    rcursor.x = (float)cursor.x / xscale;
    rcursor.y = (float)cursor.y / yscale;
    return rcursor;
}


sfBool store_rclick(sfVector2f click, entity_t *entity)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(E_RSPRITE->sprite);

    if (E_INTERACT->click_right == ON &&
        sfFloatRect_contains(&rect, click.x, click.y)) {
        E_INTERACT->is_rclick = ON;
        E_INTERACT->rclick = click;
        return sfTrue;
    }
    return sfFalse;
}

sfBool store_lclick(sfVector2f click, entity_t *entity)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(E_RSPRITE->sprite);

    if (E_INTERACT->click_left == ON &&
    sfFloatRect_contains(&rect, click.x, click.y)) {
        E_INTERACT->is_lclick = ON;
        E_INTERACT->lclick = click;
        return sfTrue;
    }
    return sfFalse;
}

void get_clicks_info(sfVector2f *right, sfVector2f *left, game_data_t *data)
{
    data->stats->click.is_rclick = OFF;
    data->stats->click.is_lclick = OFF;
    data->stats->click_log.is_rclick = OFF;
    data->stats->click_log.is_lclick = OFF;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        *left = get_cursor_pos(data);
        data->stats->click.is_lclick = ON;
        data->stats->click_log.is_lclick = ON;
    }
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        *right = get_cursor_pos(data);
        data->stats->click.is_rclick = ON;
        data->stats->click_log.is_rclick = ON;
    }
}

void check_inputs(game_data_t *data, entity_list_t *interacts,
sfVector2f *right, sfVector2f *left)
{
    entity_list_t *list = interacts;

    for (; list && (data->stats->click.is_rclick
    || data->stats->click.is_lclick); list = list->next) {
        if (!list->E_INTERACT || list->E_INTERACT == OFF ||
        (list->E_INTERACT->click_right == OFF
        && list->E_INTERACT->click_left == OFF) || list->entity->toggle == OFF)
            continue;
        if (data->stats->click.is_rclick
        && store_rclick(*right, list->entity)) {
            data->stats->click.is_rclick = OFF;
            *right = (sfVector2f){0, 0};
        } if (data->stats->click.is_lclick
        && store_lclick(*left, list->entity)) {
            data->stats->click.is_lclick = OFF;
            *left = (sfVector2f){0, 0};
        }
    }
}
