/*
** EPITECH PROJECT, 2020
** text_utils.c
** File description:
** header for text_utils.c
*/

#include "my_csfml.h"

// TEXT TOGGLE
// TODO : TOGGLE FOR SPECIFIC TEXT
void toggle_textlist_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_TEXT == NULL)
        return;
    E_TEXT->toggle = toggle;
}

int get_text_idx_fromactual(entity_t *entity, char *id)
{
    int i = 0;

    for (;i < E_TEXT->count; i++) {
        if (!my_strcmp(E_TEXT->text[i].id, id))
            return i;
    }
    return -1;
}

void toggle_text_fromactual(entity_t *entity, char *id, toggle_t toggle)
{
    int idx = get_text_idx_fromactual(entity, id);

    if (idx == -1)
        return;
    E_TEXT->text[idx].toggle = toggle;
}

void toggle_text_fromlist(entity_t *list, char *ename,
                          char *id, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, ename);

    if (entity == NULL)
        return;
    toggle_text_fromactual(entity, id, toggle);
}