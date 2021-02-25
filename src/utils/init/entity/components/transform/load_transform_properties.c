/*
** EPITECH PROJECT, 2020
** load_transform_toggle.c
** File description:
** load_transform_toggle.c
*/

#include "utils/init_xfml.h"
#include "utils/init/entity/components/transform/load_transform_component.h"
#include "../../../../../../include/my.h"

void load_transform_toggle(char *content, int *i, transform_t *transform)
{
    transform->toggle = fill_toogle(content, i);
}

void load_transform_rotation(char *content, int *i, transform_t *transform)
{
    char *value = extract_value(content, i);
    transform->rotation = my_getnbr_f(value);

    free(value);
}