/*
** EPITECH PROJECT, 2020
** set_text_id.c
** File description:
** set_text_id.c
*/

#include <stdlib.h>
#include "../../../../../../include/my_csfml.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../../../include/my.h"
#include "my_puterr.h"

void set_text_id(char *content, int *i, text_t *text)
{
    text->id = extract_value(content, i);
}

void set_text_offset(char *content, int *i, text_t *text)
{
    char *path = extract_value(content, i);
    char **pos = my_str_to_tab(path, ' ');
    int j = 0;

    if (pos == NULL)
        my_puterr("Malloc error in my_str_to_tab", __FILE__, __LINE__);
    for (; pos[j]; j++);
    if (j != 2)
        my_puterr("Incorrect position coords", __FILE__, __LINE__);
    text->offset.x = (float)my_getnbr(pos[0]);
    text->offset.y = (float)my_getnbr(pos[1]);
    free(path);
    free(pos[0]);
    free(pos[1]);
    free(pos);
}
