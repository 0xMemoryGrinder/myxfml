/*
** EPITECH PROJECT, 2020
** create_video.c
** File description:
** header for create_video.c
*/

#include "my_csfml.h"
#include "utils/init_xfml.h"
#include "my.h"
#include "my_puterr.h"

void get_canvas_size(char *content, int *i, game_data_t *data)
{
    int j = 0;
    char *scale = extract_value(content, i);
    float x = (float)my_getnbr(scale);
    float y;
    for (;scale[j] != ' '; j++);
    j++;
    y = (float)my_getnbr(scale + j);
    free(scale);
    data->stats->camera->transform->scale.x = x;
    data->stats->camera->transform->scale.y = y;
}

void get_video_data(char *content, int *i, game_data_t *data)
{
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</video>", 8)) {
        skip_to_next_tag(content, i, OPEN);
        k = 0;
    while (video_conf_tags[k].tag && my_strncmp(content + *i,
    video_conf_tags[k].tag, video_conf_tags[k].tag_len))
            k++;
        if (!video_conf_tags[k].tag)
            my_puterr("Unrecognized video tag", __FILE__, __LINE__);
        *i += video_conf_tags[k].tag_len;
        video_conf_tags[k].action(content, i, data);
        *i += video_conf_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}

void get_audio_data(char *content, int *i, game_data_t *data)
{
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</audio>", 8)) {
        skip_to_next_tag(content, i, OPEN);
        k = 0;
        while (audio_conf_tags[k].tag && my_strncmp(content + *i,
        audio_conf_tags[k].tag, audio_conf_tags[k].tag_len))
            k++;
        if (!audio_conf_tags[k].tag)
            my_puterr("Unrecognized audio_settings tag", __FILE__, __LINE__);
        *i += audio_conf_tags[k].tag_len;
        audio_conf_tags[k].action(content, i, data);
        *i += audio_conf_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}

void get_settings(char *content, int *i, game_data_t *data)
{
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</game_settings>", 16)) {
        skip_to_next_tag(content, i, OPEN);
        k = 0;
        while (settings_conf_tags[k].tag && my_strncmp(content + *i,
        settings_conf_tags[k].tag,
        settings_conf_tags[k].tag_len))
            k ++;
        if (! settings_conf_tags[k].tag)
            my_puterr("Unrecognized entity tag", __FILE__, __LINE__);
        *i += settings_conf_tags[k].tag_len;
        settings_conf_tags[k].action(content, i, data);
        *i += settings_conf_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}