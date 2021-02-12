/*
** EPITECH PROJECT, 2020
** insert_globals.c
** File description:
** header for insert_globals.c
*/

#include "my_csfml.h"
#include "my.h"
#include "utils/init_xfml.h"
#include "my_puterr.h"

void insert_global_entity(char *content, int *i,
scene_id id, game_data_t *data)
{
    char *name = NULL;
    entity_t *entity = NULL;

    if (content[*i] != '\n' && ! my_strncmp(content + *i, "all", 3)) {
        insert_entities_inlists(data->global_entity,
                                data->scenes->list[id].objects, sfFalse);
        return;
    }
    while(my_strncmp(content + *i, "</globals>", 10)) {
        skip_to_next_tag(content, i, false);
        *i += 8;
        name = extract_value(content, i);
        i += 9;
        entity = get_entity_name(data->global_entity, name);
        insert_entity_inlists(entity, data->scenes->list[id].objects, sfFalse);
        free(name);
        skip_to_next_tag(content, i, true);
    }
}

void insert_player_entity(char *content, int *i,
scene_id id, game_data_t *data)
{
    char *name = NULL;
    entity_t *entity = NULL;

    if (content[*i] != '\n' && ! my_strncmp(content + *i, "all", 3)) {
        insert_entities_inlists(data->player,
                                data->scenes->list[id].objects, sfFalse);
        return;
    }
    while(my_strncmp(content + *i, "</player>", 9)) {
        skip_to_next_tag(content, i, false);
        *i += 8;
        name = extract_value(content, i);
        i += 9;
        entity = get_entity_name(data->player, name);
        insert_entity_inlists(entity, data->scenes->list[id].objects, sfFalse);
        free(name);
        skip_to_next_tag(content, i, true);
    }
}

void insert_gui_entity(char *content, int *i,
scene_id id, game_data_t *data)
{
    char *name = NULL;
    entity_t *entity = NULL;

    if (content[*i] != '\n' && ! my_strncmp(content + *i, "all", 3)) {
        insert_entities_inlists(data->global_entity,
        data->scenes->list[id].objects, sfTrue);
        return;
    }
    while(my_strncmp(content + *i, "</gui>", 6)) {
        skip_to_next_tag(content, i, false);
        *i += 8;
        name = extract_value(content, i);
        i += 9;
        entity = get_entity_name(data->global_entity, name);
        insert_entity_inlists(entity, data->scenes->list[id].objects, sfTrue);
        free(name);
        skip_to_next_tag(content, i, true);
    }
}

void insert_globals_in_scene(char *content, int *i,
scene_id id ,game_data_t *data)
{
    int k;

    while (my_strncmp(content + *i, "</insert>", 9)) {
        k = 0;
        skip_to_next_tag(content, i, false);
        while (insert_conf_tags[k].tag && my_strncmp(content + *i,
        insert_conf_tags[k].tag, insert_conf_tags[k].tag_len))
            k++;
        if (!insert_conf_tags[k].tag)
            my_puterr("Unrecognized scene tag", __FILE__, __LINE__);
        *i += insert_conf_tags[k].tag_len;
        insert_conf_tags[k].action(content, i, id, data);
        *i += insert_conf_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, true);
    }
}