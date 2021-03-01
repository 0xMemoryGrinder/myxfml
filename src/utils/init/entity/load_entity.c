/*
** EPITECH PROJECT, 2020
** entity_loader.c
** File description:
** entity_loader.c
*/

#include <stdlib.h>
#include "utils/init/entity/components/load_components.h"
#include "graphic_engine/render_fonctions.h"
#include "utils/init/entity/load_entity_properties.h"
#include "my_puterr.h"
#include "my_xml.h"
#include "my.h"

int iterate_entity_file(xmlnode_t *node, entity_t *entity)
{
    int good;

    if (!load_entity_name(node, entity) || !load_entity_type(node, entity) ||
    !load_entity_toggle(node, entity))
        return 0;
    for (int i = 0; i < node->children.size; i++) {
        if (!my_strcmp(node->children.data[i]->tag, "components"))
            good = load_components(node->children.data[i], entity);
        else if (!my_strcmp(node->children.data[i]->tag, "children"))
            good = load_entity_children(node->children.data[i], entity);
        else
            return my_puterr("Unknown entity tag", __FILE__, __LINE__).nb;
        if (!good)
            return 0;
    }
    return 1;
}

entity_t *load_entity(char *filepath, entity_t *parent)
{
    xmldoc_t *doc = load_xmldoc(filepath);
    entity_t *entity = malloc_entity_node();
    xmlnode_t *node;
    int good;

    if (doc == NULL || entity == NULL)
        return NULL;
    node = doc->root;
    if (parent != NULL)
        entity->parent = parent;
    good = iterate_entity_file(node, entity);
    if (!good)
        return NULL;
    if (E_ANIMATION)
        update_anim_state(entity);
    if (E_RSPRITE && E_TRANSFORM)
        sfSprite_setPosition(E_RSPRITE->sprite, E_TRANSFORM->position);
    return entity;
}

/*
int main()
{
    entity_t *test = load_entity("conf/entity_templates/template_with_child.xml", NULL);
    return 0;
} */