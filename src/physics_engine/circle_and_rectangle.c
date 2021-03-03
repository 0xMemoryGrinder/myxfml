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

    return distance < radius;
}

static sfBool check_edges(sfVector2f circ_pos, sfVector2f *edges, float radius)
{
    for (int i = 0; i < 4; i++) {
        if (check_edge(circ_pos, edges[i], radius))
            return sfTrue;
    }
    return sfFalse;
}

static sfBool check_vertex(sfVector2f circ_pos, sfVector2f p1, sfVector2f p2,
                           float radius)
{
    float pts_distance = sqrtf(powf((p1.x - p2.x), 2.0f) +
                               powf((p1.y - p2.y), 2.0f));
    float distance;

    if (pts_distance == 0.0)
        return sfFalse;
    distance = fabsf((p2.x - p1.x) * (p1.y - circ_pos.y) - (p1.x - circ_pos.x)
                                                           * (p2.y - p1.y)) / pts_distance;
    return distance < radius;
}

static sfBool check_vertexes(sfVector2f circ_pos, sfVector2f *corners, float radius)
{
    if (check_vertex(circ_pos, corners[0], corners[1], radius) ||
        check_vertex(circ_pos, corners[1], corners[2], radius) ||
        check_vertex(circ_pos, corners[2], corners[3], radius) ||
        check_vertex(circ_pos, corners[3], corners[0], radius))
        return sfTrue;
    return sfFalse;
}

sfBool circle_and_rectangle( sfCircleShape *circle,
sfRectangleShape *rect_coll, float radius)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(rect_coll);
    sfVector2f circle_pos = sfCircleShape_getPosition(circle);
    sfVector2f rect_corners_pos[4];
    get_corners_position(rect, rect_corners_pos);

    if (sfFloatRect_contains(&rect, circle_pos.x, circle_pos.y) ||
        check_vertexes(circle_pos, rect_corners_pos, radius) ||
        check_edges(circle_pos, rect_corners_pos, radius)) {
        return sfTrue;
    }
    return sfFalse;
}