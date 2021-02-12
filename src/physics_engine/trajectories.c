/*
** EPITECH PROJECT, 2020
** trajectories.c
** File description:
** header for trajectories.c
*/

#include "../../include/my_csfml.h"
#include <math.h>


sfVector3f get_angle(sfVector2f direction, sfVector3f to_return, float speed)
{
    if (direction.x != 0) {
        to_return.z = atan2f(direction.y, direction.x);
        to_return.x = speed * cosf(to_return.z);
        to_return.y = speed * sinf(to_return.z);
    }
    return to_return;
}

sfVector3f ajust_vector(sfVector3f to_return, float speed,
sfVector2f direction)
{
    if (direction.x == 0) {
        if (direction.y > 0) {
            to_return.y = speed;
            to_return.z = - 1.0f * (float) M_PI_2;
        } else if (direction.y < 0) {
            to_return.y = speed * (- 1);
            to_return.z = M_PI_2;
        }
    }
    return to_return;
}

sfVector3f get_direction(sfVector2f position, float speed, sfVector2f target)
{
    sfVector2f direction = {0, 0};
    sfVector3f to_return = {0, 0, 0};

    direction.x = target.x - position.x;
    direction.y = target.y - position.y;
    to_return = get_angle(direction, to_return, speed);
    to_return = ajust_vector(to_return, speed, direction);
    if (to_return.x > direction.x && direction.x > 0)
        to_return.x = direction.x;
    if (to_return.y > direction.y && direction.y > 0)
        to_return.y = direction.y;
    return to_return;
}