/*
** EPITECH PROJECT, 2020
** load_texts_properties.c
** File description:
** load_texts_properties.c
*/

#include <stdlib.h>
#include "my_csfml.h"
#include "utils/init/load_file.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init/common_tags.h"

void load_text_toggle(char *content, int *i, text_t *text)
{
    text->toggle = fill_toogle(content, i);
}

void load_text_font(char *content, int *i, text_t *text)
{
    char *path = extract_value(content, i);
    text->font = sfFont_createFromFile(path);

    free(path);
}

void load_text_position(char *content, int *i, text_t *text)
{
    char *path = extract_value(content, i);
    char **pos = my_str_to_tab(path, ' ');
    int j = 0;

    if (pos == NULL)
        my_puterr("Malloc error in my_str_to_tab", __FILE__, __LINE__);
    for (; pos[j]; j++);
    if (j != 2)
        my_puterr("Incorrect position coords", __FILE__, __LINE__);
    text->pos.x = (float)my_getnbr(pos[0]);
    text->pos.y = (float)my_getnbr(pos[1]);
    free(path);
    free(pos[0]);
    free(pos[1]);
    free(pos);
}

void load_text_font_size(char *content, int *i, text_t *text)
{
    int path_len = length_of_tag_value(content, *i);
    char *path = my_strndup(content + *i, path_len);
    *i += path_len;

    if (path == NULL)
        my_puterr("Malloc error in strndup", __FILE__, __LINE__);
    text->size = my_getnbr(path);
    free(path);
}

void load_text_string(char *content, int *i, text_t *text)
{
    int path_len = length_of_tag_value(content, *i);
    char *path = my_strndup(content + *i, path_len);
    *i += path_len;

    if (path == NULL)
        my_puterr("Malloc error in strndup", __FILE__, __LINE__);
    text->string = path;
}