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

//
//  Game Globals
//
void get_global_entities(char *content, int *i, game_data_t *data)
{
    char *name = NULL;
    char *path;
    data->global_entity = malloc_entity_node();
    entity_t *recept = NULL;

    while (my_strncmp(content + *i, "</globals>", 10)) {
        skip_to_next_tag(content, i, false);
        *i += entity_tag.tag_len;
        name = extract_value(content , i);
        *i += entity_tag.tag_len + 1;
        path = my_strcat(GLOBAL_PATH, name);
        recept = load_entity(path, NULL);
        free(name);
        add_entity(recept, &data->global_entity);
        skip_to_next_tag(content, i, true);
    }
    //*i += 10; TODO : CHECK IT
}

void get_player_entities(char *content, int *i, game_data_t *data)
{
    char *name = NULL;
    char *path;
    data->player = malloc_entity_node();
    entity_t *recept = NULL;

    while (my_strncmp(content + *i, "</player>", 9)) {
        skip_to_next_tag(content, i, false);
        *i += entity_tag.tag_len;
        name = extract_value(content , i);
        *i += entity_tag.tag_len + 1;
        path = my_strcat(PLAYER_PATH, name);
        recept = load_entity(path, NULL);
        free(name);
        free(path);
        add_entity(recept, &data->player);
        skip_to_next_tag(content, i, true);
    }
    //*i += 9; TODO CHECK NESCECITY
}

void get_gui_entities(char *content, int *i, game_data_t *data)
{
    char *name = NULL;
    char *path;
    data->gui = malloc_entity_node();
    entity_t *recept = NULL;

    while (my_strncmp(content + *i, "</gui>", 6)) {
        skip_to_next_tag(content, i, false);
        *i += entity_tag.tag_len;
        name = extract_value(content , i);
        *i += entity_tag.tag_len + 1;
        path = my_strcat(GUI_PATH, name);
        recept = load_entity(path, NULL);
        free(name);
        free(path);
        add_entity(recept, &data->gui);
        skip_to_next_tag(content, i, true);
    }
    //*i += 6; TODO : CHECK NESCECITY
}
