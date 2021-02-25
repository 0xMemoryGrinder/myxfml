/*
** EPITECH PROJECT, 2020
** script_data_utils.c
** File description:
** header for script_data_utils.c
*/

#include "my_csfml.h"

void *get_script_data_fromlist(entity_t *entity,
char *ename, char *sname)
{
    script_t *script = get_script_fromlist(entity, ename, sname);

    if (script == NULL)
        return NULL;
    return script->data;
}

void *get_script_data_fromactual(entity_t *entity, char *sname)
{
    script_t *script = get_script_fromactual(entity, sname);

    if (script == NULL)
        return NULL;
    return script->data;
}