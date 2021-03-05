/*
** EPITECH PROJECT, 2020
** entity_loader.c
** File description:
** entity_loader.c
*/

#include <stdlib.h>
#include "utils/init_xfml.h"
#include "utils/init/entity/components/load_components.h"
#include "graphic_engine/render_fonctions.h"
#include "utils/init/entity/load_entity_properties.h"
#include "my_puterr.h"
#include "my_xml.h"
#include "my.h"

int load_entity_on_destroy(xmlnode_t *node, entity_t *entity)
{
    int status = 1;
    char *content = xml_value_str("action", node, &status);

    if (!status)
        return 0;
    entity->on_destroy = fill_function(content, destroy_entity_func_ptr_tab,
    &status);
    free(content);
    if (!status)
        return 0;
    return 1;
}

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
    free_xmlnode(doc->root);
    free(doc);
    return entity;
}

entity_t *gen_entity_fromnode(xmlnode_t *node, entity_t *parent,
game_data_t *data, sfBool is_insert)
{
    char *path = get_entity_path(node, G_ACTUAL_SCENE.name);
    entity_t *entity = load_entity(path, parent);
    int status = 1;

    if (!entity)
        return NULL;
    if (xml_toggle("modify", node, &status) == 1)
        moddify_entity(node, entity);
    if (is_insert)
        insert_entity_inlists(entity, G_ACTUAL_SCENEOBJS, false);
    free(path);
    return entity;
}

entity_t *gen_entity_template_byname(char *name, entity_t *parent,
game_data_t *data, sfBool is_insert)
{
    char *path = my_multiple_strcat(3, "conf/entity_templates/",
    name , ".xml");
    entity_t *entity;

    if (path == NULL)
        return NULL;
    entity = load_entity(path, parent);
    if (!entity)
        return NULL;
    if (is_insert)
        insert_entity_inlists(entity, G_ACTUAL_SCENEOBJS, false);
    free(path);
    return entity;
}