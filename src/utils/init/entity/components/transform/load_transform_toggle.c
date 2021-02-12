/*
** EPITECH PROJECT, 2020
** load_transform_toggle.c
** File description:
** load_transform_toggle.c
*/

#include "utils/init_xfml.h"
#include "load_transform_component.h"
#include "../../../../../../include/my.h"

void load_transform_toggle(char *content, int *i, transform_t *transform)
{
    transform->toggle = fill_toogle(content, i);
}