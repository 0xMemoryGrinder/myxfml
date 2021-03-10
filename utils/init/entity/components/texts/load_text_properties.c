/*
** EPITECH PROJECT, 2020
** load_texts_properties.c
** File description:
** load_texts_properties.c
*/

#include <stdlib.h>
#include "my_xml.h"
#include "my_csfml.h"
#include "my.h"

int load_text_toggle(xmlnode_t *node, text_t *text)
{
    int status = 1;
    text->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_text_font(xmlnode_t *node, text_t *text)
{
    int status = 1;
    char *path = xml_value_str("path", node, &status);

    if (!status)
        return 0;
    text->font = sfFont_createFromFile(path);
    free(path);
    return 1;
}

int load_text_position(xmlnode_t *node, text_t *text)
{
    int status1 = 1;
    int status2 = 1;
    text->pos.x = (float)xml_value_int("xpos", node, &status1);
    text->pos.y = (float)xml_value_int("ypos", node, &status2);

    if (!status1 || !status2)
        return 0;
    return 1;
}

int load_text_font_size(xmlnode_t *node, text_t *text)
{
    int status = 1;
    text->size = xml_value_int("font-size", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_text_string(xmlnode_t *node, text_t *text)
{
    int status =1;
    text->string = xml_value_str("string", node, &status);

    if (!status)
        return 0;
    return 1;
}