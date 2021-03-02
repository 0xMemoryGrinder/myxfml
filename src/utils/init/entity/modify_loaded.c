/*
** EPITECH PROJECT, 2020
** modify_loaded.c
** File description:
** header for modify_loaded.c
*/

#include <my_puterr.h>
#include "my_csfml.h"
#include "my_xml.h"
#include "utils/init_xfml.h"

static int modify_transform(xmlnode_t *node, entity_t *entity)
{
    if (!E_TRANSFORM)
        return -1;
    if (!mod_toggle(node, &E_TRANSFORM->toggle, "trans-toggle") ||
    !mod_float_value(node, &E_TRANSFORM->position.x, "trans-x") ||
    !mod_float_value(node, &E_TRANSFORM->position.y, "trans-y") ||
    !mod_float_value(node, &E_TRANSFORM->speed, "trans-speed"))
        return 0;
    if (E_RSPRITE)
        sfSprite_setPosition(E_RSPRITE->sprite, E_TRANSFORM->position);
    return 1;
}

static int modify_collider(xmlnode_t *node, entity_t *entity)
{
    if (!E_COLLIDER)
        return -1;
    if (!mod_toggle(node, &E_COLLIDER->toggle, "coll-toggle") ||
    !mod_float_value(node, &E_COLLIDER->position.x, "coll-x") ||
    !mod_float_value(node, &E_COLLIDER->position.y, "coll-y") ||
    !mod_float_value(node, &E_COLLIDER->dimensions.x, "coll-w") ||
    !mod_float_value(node, &E_COLLIDER->dimensions.y, "coll-h"))
        return 0;
    return 1;
}

static int modify_render(xmlnode_t *node, entity_t *entity)
{
    if (E_RSPRITE)
        if (!mod_toggle(node, &E_RSPRITE->toggle, "render-toggle"))
            return 0;
    if (E_ANIMATION)
        if (!mod_toggle(node , &E_ANIMATION->toggle, "anim-toggle"))
            return 0;
    return 1;
}

static int modify_interact(xmlnode_t *node, entity_t *entity)
{
    if (!E_INTERACT)
        return -1;
    if (!mod_toggle(node, &E_INTERACT->click_left, "int-lclick") ||
    !mod_toggle(node, &E_INTERACT->click_right, "int-rclick") ||
    !mod_toggle(node, &E_INTERACT->toggle, "int-toggle"))
        return 0;
    return 1;
}
// TODO : modify text / scripts / sounds
int moddify_entity(xmlnode_t *node, entity_t *entity)
{
    if (!mod_toggle(node, &entity->toggle, "entity-toggle") ||
    !mod_str(node, &entity->name,"entity-name") ||
    !modify_collider(node, entity) || !modify_render(node, entity) ||
    !modify_transform(node, entity) || !modify_interact(node, entity)) {
        return my_puterr("Modify loaded entity error", __FILE__, __LINE__).nb;
    }
    if (E_TEXT)
        mod_toggle(node, &E_TEXT->toggle, "texts-toggle");
    if (E_SOUND)
        mod_toggle(node, &E_SOUND->toggle, "sounds-toggle");
    if (E_SCRIPT)
        mod_toggle(node, &E_SCRIPT->toggle ,"scripts-toggle");
    return 1;
}