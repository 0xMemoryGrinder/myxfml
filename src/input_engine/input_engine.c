/*
** EPITECH PROJECT, 2020
** input_engine.c
** File description:
** header for input_engine.c
*/

#include "../../include/my_csfml.h"

sfBool store_rclick(sfVector2i click, entity_t *entity)
{
    if (E_INTERACT->click_right == ON &&
    sfIntRect_contains(&ACTUAL_CROP.crop, click.x, click.y)) {
        E_INTERACT->is_rclick = ON;
        return sfTrue;
    }
    return sfFalse;
}

sfBool store_lclick(sfVector2i click, entity_t *entity)
{
    if (E_INTERACT->click_left == ON &&
    sfIntRect_contains(&ACTUAL_CROP.crop, click.x, click.y)) {
        E_INTERACT->is_lclick = ON;
        return sfTrue;
    }
    return sfFalse;
}

void get_clicks_info(sfVector2i *right, sfVector2i *left, game_data_t *data)
{
    data->stats->is_rclick = OFF;
    data->stats->is_lclick = OFF;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        *left = sfMouse_getPositionRenderWindow(G_WINDOW);
        data->stats->is_lclick = ON;
    }
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        *right = sfMouse_getPositionRenderWindow(G_WINDOW);
        data->stats->is_rclick = ON;
    }
}

void check_inputs(game_data_t *data, entity_list_t *interacts,
sfVector2i right, sfVector2i left)
{
    entity_list_t *list = interacts;

    for (; list && (data->stats->is_rclick || data->stats->is_lclick);
    list = list->next) {
        if (list->E_INTERACT == OFF || (list->E_INTERACT->click_right == OFF
        && list->E_INTERACT->click_left == OFF) || list->entity->toggle == OFF)
            continue;
        if (data->stats->is_rclick && store_rclick(right, list->entity)) {
            data->stats->is_rclick = OFF;
            right = (sfVector2i){0, 0};
        } if (data->stats->is_lclick && store_lclick(left, list->entity)) {
            data->stats->is_lclick = OFF;
            left = (sfVector2i){0, 0};
        }
    }
    data->stats->lclick = left;
    data->stats->rclick = right;
}
