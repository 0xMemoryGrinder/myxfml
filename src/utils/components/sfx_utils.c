/*
** EPITECH PROJECT, 2020
** sfx_utils.c
** File description:
** header for sfx_utils.c
*/

#include "my_csfml.h"

void toggle_sfxlist_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_SOUND == NULL)
        return;
    E_SOUND->toggle = toggle;
}

void toggle_sfx_fromactual(entity_t *entity, char *sname, toggle_t toggle)
{
    if (entity == NULL || E_SOUND == NULL)
        return;
    for (int i = 0; i < E_SOUND->sfx_count; i++) {
        if (!my_strcmp(sname, E_SOUND->sfx[i].name))
            E_SOUND->sfx[i].toggle = toggle;
    }
}

void toggle_sfx_fromlist(entity_t *list, char *ename,
                         char *sname, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, ename);

    if (entity == NULL)
        return;
    toggle_sfx_fromactual(entity, sname, toggle);
}