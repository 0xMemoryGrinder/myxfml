/*
** EPITECH PROJECT, 2020
** entity_loader.c
** File description:
** entity_loader.c
*/

#include <stdlib.h>
#include "graphic_engine/render_fonctions.h"
#include "../../../../include/utils/init/entity/load_entity.h"
#include "../../../../include/utils/init/load_file.h"
#include "my_puterr.h"
#include "../../../../include/my.h"

void iterate_entity_file(char *content, int *i, entity_t *entity)
{
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</entity>", 9)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (entity_conf_tag_action[k].tag && my_strncmp(content + *i,
        entity_conf_tag_action[k].tag, entity_conf_tag_action[k].tag_len))
            k++;
        if (!entity_conf_tag_action[k].tag)
            my_puterr("Unrecognized entity tag", __FILE__, __LINE__);
        *i += entity_conf_tag_action[k].tag_len;
        entity_conf_tag_action[k].action(content, i, entity);
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
    }
}

entity_t *load_entity(char *filepath, entity_t *parent)
{
    char *content = load_file(filepath);
    entity_t *entity = malloc_entity_node();
    int i = 2;

    if (parent != NULL)
        entity->parent = parent;
    iterate_entity_file(content, &i, entity);
    free(content);
    if (E_ANIMATION)
        update_anim_state(entity);
    if (E_RSPRITE && E_TRANSFORM)
        sfSprite_setPosition(E_RSPRITE->sprite, E_TRANSFORM->position);
    return entity;
}