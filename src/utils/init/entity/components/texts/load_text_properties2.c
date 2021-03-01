/*
** EPITECH PROJECT, 2020
** set_text_id.c
** File description:
** set_text_id.c
*/

#include <stdlib.h>
#include "my_xml.h"
#include "my_csfml.h"
#include "utils/init/load_file.h"
#include "my.h"
#include "my_puterr.h"

int load_text_id(xmlnode_t *node, text_t *text)
{
    int status = 1;
    text->id = xml_value_str("id", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_text_offset(xmlnode_t *node, text_t *text)
{
    int status1 = 1;
    int status2 = 1;
    text->offset.x = (float)xml_value_int("xoffset", node, &status1);
    text->offset.y = (float)xml_value_int("yoffset", node, &status2);

    if (!status1 || !status2)
        return 0;
    return 1;
}
