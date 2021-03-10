/*
** EPITECH PROJECT, 2020
** circle_and_rectangle.c
** File description:
** header for circle_and_rectangle.c
*/

#include "my_csfml.h"
#include <math.h>

void get_corners_position(sfFloatRect rect, sfVector2f tab[4]);

static sfBool check_edge(sfVector2f circ_pos, sfVector2f edge, float radius)
{
    float distance = sqrtf(powf((edge.x - circ_pos.x), 2.0f) +
                           powf((edge.y - circ_pos.y), 2.0f));

    if (distance < radius)
        return sfTrue;
    else
        return sfFalse;
}

static sfBool check_edges(sfVector2f circ_pos, sfVector2f *edges, float radius)
{
    for (int i = 0; i < 4; i++) {
        if (check_edge(circ_pos, edges[i], radius))
            return sfTrue;
    }
    return sfFalse;
}
static sfBool check_vertex(sfVector2f circ_pos, sfFloatRect rect, float radius)
{
    float delta_x = circ_pos.x - fmaxf(rect.left,
    fminf(circ_pos.x, rect.left + rect.width));
    float delta_y = circ_pos.y - fmaxf(rect.top,
    fminf(circ_pos.y, rect.top + rect.height));

    return (delta_x * delta_x + delta_y * delta_y) < (radius * radius);
}

sfBool circle_and_rectangle( sfCircleShape *circle,
sfRectangleShape *rect_coll, float radius)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(rect_coll);
    sfVector2f circle_pos = sfCircleShape_getPosition(circle);
    sfVector2f rect_corners_pos[4];
    get_corners_position(rect, rect_corners_pos);

    if (sfFloatRect_contains(&rect, circle_pos.x, circle_pos.y) ||
        check_vertex(circle_pos, rect, radius)  ||
        check_edges(circle_pos, rect_corners_pos, radius)) {
        return sfTrue;
    }
    return sfFalse;
}