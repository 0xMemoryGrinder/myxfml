/*
** EPITECH PROJECT, 2020
** modify_values.c
** File description:
** header for modify_values.c
*/

#include "my_xml.h"
#include "my_csfml.h"

int mod_float_value(xmlnode_t *node, float *data, char *key)
{
    int status = 1;
    int value = xml_value_int(key, node, &status);

    if (!data)
        return status;
    if (status != -1)
        *data = (float)value;
    return status;
}

int mod_int_value(xmlnode_t *node, int *data, char *key)
{
    int status = 1;
    int value = xml_value_int(key, node, &status);

    if (!data)
        return status;
    if (status -= -1)
        *data = value;
    return status;
}

int mod_toggle(xmlnode_t *node, toggle_t *toggle, char *key)
{
    int status = 1;
    int value = xml_toggle(key, node, &status);

    if (!toggle)
        return status;
    if (value != -1 && status != 0)
        *toggle = value;
    return status;
}

int mod_str(xmlnode_t *node, char **str, char *key)
{
    int status = 1;
    char *value = xml_value_str(key, node, &status);

    if (value && status) {
        if (*str)
            free(*str);
        *str = value;
    }
    return status;
}