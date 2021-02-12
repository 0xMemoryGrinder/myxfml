/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** header for init_game.c
*/

#include "../../../include/my_csfml.h"
#include "../../../include/utils/init_xfml.h"
#include "../../../include/my.h"
#include "my_puterr.h"

#define GAME_CONF "conf/game_cfg.xml"

game_data_t *malloc_game(void);

void iterate_game_cfg_file(char *content, int *i, game_data_t *data)
{
    int k;

    while (my_strncmp(content + *i, "</entity>", 9)) {
        skip_to_next_tag(content, i, false);
        k = 0;
        while (game_conf_tags[k].tag && my_strncmp(content + *i,
        game_conf_tags[k].tag, game_conf_tags[k].tag_len))
            k++;
        if (!game_conf_tags[k].tag)
            my_puterr("Unrecognized entity tag", __FILE__, __LINE__);
        *i += game_conf_tags[k].tag_len;
        game_conf_tags[k].action(content, i, data);
        *i += game_conf_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, true);
    }
}

void load_game_conf(char *path, game_data_t *data)
{
    char *content = load_file(path);
    int i = 1;

    skip_to_next_tag(content, &i, false);
    iterate_game_cfg_file(content, &i, data);
    free(content);
}

game_data_t *create_game(void)
{
    game_data_t *data = malloc_game();

    load_game_conf(GAME_CONF, data);
    data->game_settings->video->mode.width = data->game_settings->video->width;
    data->game_settings->video->mode.height =
    data->game_settings->video->height;
    data->game_settings->video->mode.bitsPerPixel = 32;
    if (data->game_settings->video->is_fullscreen)
        G_WINDOW = sfRenderWindow_create(data->game_settings->video->mode,
        data->game_settings->video->game_title, sfFullscreen, NULL);
    else
        G_WINDOW = sfRenderWindow_create(data->game_settings->video->mode,
        data->game_settings->video->game_title, sfClose, NULL);
    return data;
}