/*
** EPITECH PROJECT, 2020
** get_globals.c
** File description:
** header for get_globals.c
*/

#include "my_csfml.h"
#include "utils/init_xfml.h"
#include "my.h"

#define GLOBAL_PATH "conf/global_entities/"
#define PLAYER_PATH "conf/player/"
#define GUI_PATH "conf/gui/"
#define XML ".xml"

//
//  Game Globals
//
void get_global_entities(char *content, int *i, game_data_t *data)
{
    char *name = NULL;
    char *path;
    char *paht2;
    data->global_entity = malloc_entity_node();
    entity_t *recept = NULL;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</globals>", 10)) {
        skip_to_next_tag(content, i, OPEN);
        *i += entity_tag.tag_len;
        name = extract_value(content , i);
        *i += entity_tag.tag_len + 1;
        path = my_strcat(GLOBAL_PATH, name);
        paht2  =my_strcat(path, XML);
        recept = load_entity(paht2, NULL);
        free(name);
        free(path);
        free(paht2);
        add_entity(recept, &data->global_entity);
        skip_to_next_tag(content, i, NEXT);
    }
}

void get_player_entities(char *content, int *i, game_data_t *data)
{
    char *name = NULL;
    char *path;
    char *path2;
    data->player = malloc_entity_node();
    entity_t *recept = NULL;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</player>", 9)) {
        skip_to_next_tag(content, i, OPEN);
        *i += entity_tag.tag_len;
        name = extract_value(content , i);
        *i += entity_tag.tag_len + 1;
        path = my_strcat(PLAYER_PATH, name);
        path2 = my_strcat(path, XML);
        recept = load_entity(path2, NULL);
        free(name);
        free(path);
        free(path2);
        add_entity(recept, &data->player);
        skip_to_next_tag(content, i, NEXT);
    }
}

void get_gui_entities(char *content, int *i, game_data_t *data)
{
    char *name = NULL;
    char *path;
    char *path2;
    data->gui = malloc_entity_node();
    entity_t *recept = NULL;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</gui>", 6)) {
        skip_to_next_tag(content, i, OPEN);
        *i += entity_tag.tag_len;
        name = extract_value(content , i);
        *i += entity_tag.tag_len + 1;
        path = my_strcat(GUI_PATH, name);
        path2 = my_strcat(path, XML);
        recept = load_entity(path2, NULL);
        free(name);
        free(path);
        free(path2);
        add_entity(recept, &data->gui);
        skip_to_next_tag(content, i, NEXT);
    }
}
