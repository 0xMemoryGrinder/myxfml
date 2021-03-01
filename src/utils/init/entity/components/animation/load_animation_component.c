/*
** EPITECH PROJECT, 2020
** load_animation_component.c
** File description:
** load_animation_component.c
*/

#include "utils/init/entity/components/animation/load_animation_component.h"
#include "my_csfml.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init/entity/components/animation/load_animation_component_tabs.h"

anim_t *load_anim(xmlnode_t *node)
{
    anim_t *anim = malloc_anim_frame();

    if (anim == NULL || !load_anim_toggle(node, anim) ||
    !load_anim_name(node, anim) || !load_anim_frames(node, anim) ||
    !load_anim_frame_action(node, anim))
        return NULL;
    return anim;
}

int load_anim_list(xmlnode_t *node, animation_t *animation)
{
    anim_t *current = NULL;
    anim_t *to_check = NULL;

    for (int n = 0; n < node->children.size; n++) {
        if (my_strcmp(node->children.data[n]->tag, "anim"))
            return *my_puterr("Unknown anim tag", __FILE__, __LINE__);
        to_check = load_anim(node->children.data[n]);
        if (!to_check)
            return 0;
        if (n == 0) {
            animation->list = to_check;
            current = animation->list;
        } else {
            current->next = to_check;
            current = current->next;
        }
    }
    return 1;
}

int load_animation_component(xmlnode_t *node, components_t *components)
{
    components->animation = malloc_animations();

    if (components->animation == NULL ||
    !load_animation_toggle(node, components->animation) ||
    !load_animation_anim_type(node, components->animation) ||
    !load_animation_actual_anim(node, components->animation) ||
    !load_animation_actual_frame(node, components->animation) ||
    !load_anim_list(node, components->animation))
        return 0;
    return 1;
}