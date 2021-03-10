/*
** EPITECH PROJECT, 2020
** load_interactive_component.c
** File description:
** load_interactive_component.c
*/

#include "my_csfml.h"
#include "utils/init_xfml.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init/common_tags.h"

int load_interact_toggle(xmlnode_t *node, interact_t *interact)
{
    int status = 1;
    interact->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_interact_left_click(xmlnode_t *node, interact_t *interact)
{
    int status = 1;
    interact->click_left = xml_toggle("left_click", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_interact_right_click(xmlnode_t *node, interact_t *interact)
{
    int status = 1;
    interact->click_right = xml_toggle("right_click", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_interactive_component(xmlnode_t *node, components_t *components)
{
    components->interact = malloc_interact();

    if (components->interact == NULL ||
    !load_interact_toggle(node, components->interact) ||
    !load_interact_left_click(node, components->interact) ||
    !load_interact_right_click(node, components->interact))
        return 0;
    return 1;
}