/*
** EPITECH PROJECT, 2020
** load_components.c
** File description:
** load_components.c
*/

#include "my_xml.h"
#include "utils/init/entity/components/load_components.h"
#include "my_csfml.h"
#include "../../../../../include/my_puterr.h"

int load_components(xmlnode_t *node, entity_t *entity)
{
    entity->components = malloc_components();
    int k;
    int good = 1;

    if (entity->components == NULL)
        return 0;
    for (int i = 0; i < node->children.size; i++) {
        k = 0;
        while (components_conf_tag_action[k].tag && my_strcmp(
        node->children.data[i]->tag, components_conf_tag_action[k].tag))
            k++;
        if (!components_conf_tag_action[k].tag)
            return *my_puterr("Unknown component tag", __FILE__, __LINE__);
        good = components_conf_tag_action[k].action(node->children.data[i],
        entity->components);
        if (!good)
            return 0;
    }
    return 1;
}