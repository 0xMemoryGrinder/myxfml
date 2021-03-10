/*
** EPITECH PROJECT, 2020
** set_sprites_pos.c
** File description:
** header for set_sprites_pos.c
*/

#include "my_csfml.h"

void set_sprite_oncenter(entity_t *entity, sfVector2f center)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(E_RSPRITE->sprite);
    E_TRANSFORM->position.x = center.x - rect.width * 0.5f;
    E_TRANSFORM->position.y = center.y - rect.height * 0.5f;
    sfSprite_setPosition(E_RSPRITE->sprite, E_TRANSFORM->position);
}

sfVector2f get_sprite_center(entity_t *entity)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(E_RSPRITE->sprite);
    sfVector2f center;

    center.x = rect.left + rect.width * 0.5f;
    center.y = rect.top + rect.height * 0.5f;
    return center;
}


static void switch_sides(sfVector2f *pos, int side,
sfVector2f new_pos, sfVector2f center)
{
    switch (side) {
        case LEFT: case UP:
            pos->x = center.x - new_pos.x;
            pos->y = center.y - new_pos.y;
            break;
        case RIGHT:
            pos->x = center.x + new_pos.x;
            pos->y = center.y - new_pos.y;
            break;
        case DOWN:
            pos->x = center.x - new_pos.x;
            pos->y = center.y + new_pos.y;
            break;
        default:
            return;
    }
}

void get_sprite_side(entity_t *entity1, entity_t *entity,
int side, float spacing)
{
    sfFloatRect r1 = sfSprite_getGlobalBounds(
    entity1->components->render->sprite);
    sfFloatRect r2 = sfSprite_getGlobalBounds(E_RSPRITE->sprite);
    sfVector2f center = get_sprite_center(entity1);
    float xlr = (r1.width * 0.5f + spacing + r2.width);
    float xtd = (r2.width * 0.5f);
    float ylr = (r2.height * 0.5f);
    float ytd = (r1.height * 0.5f + spacing + r2.height);

    if (side == LEFT || side == RIGHT) {
        if (side == RIGHT)
            xlr -= r2.width;
        switch_sides(&E_TRANSFORM->position, side,
        (sfVector2f) {xlr, ylr}, center);
    } else {
        if (side == DOWN)
            ytd -= r2.height;
        switch_sides(&E_TRANSFORM->position, side,
        (sfVector2f) {xtd, ytd}, center);
    } sfSprite_setPosition(E_RSPRITE->sprite, E_TRANSFORM->position);
}