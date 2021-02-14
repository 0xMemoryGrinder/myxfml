/*
** EPITECH PROJECT, 2020
** load_animation_component.c
** File description:
** load_animation_component.c
*/

#include "utils/init/entity/components/animation/load_animation_component.h"
#include "my_csfml.h"
#include "utils/init/load_file.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init/entity/components/animation/load_animation_component_tabs.h"

anim_t *load_anim(char *content, int *i)
{
    anim_t *anim = malloc_anim_frame();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</anim>", 7)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (anim_conf_tag_action[k].tag && my_strncmp(content + *i,
        anim_conf_tag_action[k].tag, anim_conf_tag_action[k].tag_len))
            k++;
        if (!anim_conf_tag_action[k].tag)
            my_puterr("Unrecognized anim tag", __FILE__, __LINE__);
        *i += anim_conf_tag_action[k].tag_len;
        anim_conf_tag_action[k].action(content, i, anim);
        *i += anim_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
    return anim;
}

void load_anim_list(char *content, int *i, animation_t *animation)
{
    int count = my_getnbr(content + *i);
    anim_t *current = NULL;

    for (int n = 0; n < count; n++) {
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
        *i += 1;
        skip_to_next_tag(content, i, OPEN);
        if (n == 0) {
            animation->list = load_anim(content, i);
            current = animation->list;
        } else {
            current->next = load_anim(content, i);
            current = current->next;
        }
        skip_to_next_tag(content, i, CLOSE);
    }
    *i += 1;
    skip_to_next_tag(content, i, CLOSE);
}

void load_animation_component(char *content, int *i, components_t *components)
{
    components->animation = malloc_animations();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</animation>", 12)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (animation_conf_tag_action[k].tag && my_strncmp(content + *i,
        animation_conf_tag_action[k].tag, animation_conf_tag_action[k].tag_len))
            k++;
        if (!animation_conf_tag_action[k].tag)
            my_puterr("Unrecognized animation tag", __FILE__, __LINE__);
        *i += animation_conf_tag_action[k].tag_len;
        animation_conf_tag_action[k].action(content, i, components->animation);
        *i += animation_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}