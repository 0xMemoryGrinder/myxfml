/*
** EPITECH PROJECT, 2020
** set_entity_properties.c
** File description:
** set_entity_properties.c
*/

#include "utils/init_xfml.h"
#include "../../../../include/my_csfml.h"
#include "../../../../include/types_and_base/entity.h"
#include "../../../../include/utils/init/load_file.h"
#include "../../../../include/my.h"
#include "../../../../include/global_tabs.h"
#include "my_puterr.h"
#include "../../../../include/utils/init/common_tags.h"

void set_entity_name(char *content, int *i, entity_t *entity)
{
    int name_len = length_of_tag_value(content, *i);
    char *name = my_strndup(content + *i, name_len);
    entity->name = name;
    *i += name_len;
}

void set_entity_type(char *content, int *i, entity_t *entity)
{
    entity->type = fill_enum(content, i, entity_type_enum_tab);
}

void set_entity_toggle(char *content, int *i, entity_t *entity)
{
    entity->toggle = fill_toogle(content, i);
}

static void load_entity_child(char *content, int *i, entity_t *entity)
{
    char *path = extract_value(content, i);

    add_entity_children(load_entity(path, entity), &(entity->children));
}

void load_entity_children(char *content, int *i, entity_t *entity)
{
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</children>", 11)) {
        skip_to_next_tag(content, i, OPEN);
        if (my_strncmp(content + *i, "<child>", 7))
            my_puterr("Unrecognized entity children tag", __FILE__, __LINE__);
        *i += 7;
        load_entity_child(content, i, entity);
        *i += entity_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}