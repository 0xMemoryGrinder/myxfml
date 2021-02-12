/*
** EPITECH PROJECT, 2020
** load_components.c
** File description:
** load_components.c
*/

#include "../../../../../include/utils/init/entity/components/load_components.h"
#include "../../../../../include/my_csfml.h"
#include "../../../../../include/types_and_base/entity.h"
#include "../../../../../include/types_and_base/base_components.h"
#include "../../../../../include/utils/init/load_file.h"
#include "../../../../../include/my.h"
#include "my_puterr.h"

void load_components(char *content, int *i, entity_t *entity)
{
    int k;
    entity->components = malloc_components();
    
    while (my_strncmp(content + *i, "</components>", 8)) {
        k = 0;
        while (components_conf_tag_action[k].tag && my_strncmp(content + *i,
        components_conf_tag_action[k].tag, components_conf_tag_action[k].tag_len))
            k++;
        if (!components_conf_tag_action[k].tag)
            my_puterr("Unrecognized texts tag", __FILE__, __LINE__);
        *i += components_conf_tag_action[k].tag_len;
        components_conf_tag_action[k].action(content, i, entity->components);
        *i += components_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }

}