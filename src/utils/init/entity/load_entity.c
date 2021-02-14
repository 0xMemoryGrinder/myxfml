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
#include "../../../../include/types_and_base/entity.h"
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
        *i += entity_conf_tag_action[k].tag_len + 1;
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
    update_anim_state(entity);
    return entity;
}


//int main(int ac, char **av)
//{
  //  entity_t *test = load_entity("../lib_myCSFML/config/main_menu/test1.xml", NULL);
    //return 0;
//}