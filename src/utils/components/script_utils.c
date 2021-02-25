/*
** EPITECH PROJECT, 2020
** script_utils.c
** File description:
** header for script_utils.c
*/

#include <stdlib.h>
#include "graphic_engine/render_fonctions.h"
#include "../../../include/my_csfml.h"
#include "../../../include/my.h"

#define G_LIST_FROM(scene_id) data->scenes->list[scene_id].objects->list
#define S_LIST_FROM(scene_id) scenes->list[scene_id].objects->list

script_t *get_script_fromactual(entity_t *entity, char *name)
{
    script_t *script;

    if (entity == NULL || E_SCRIPT == NULL)
        return NULL;
    script = E_SCRIPT->list;
    for (; script; script = script->next) {
        if (!my_strcmp(name, script->name))
            return script;
    }
    return NULL;
}

script_t *get_script_fromlist(entity_t *list, char *ename, char *sname)
{
    entity_t *entity = get_entity_name(list, ename);

    if (entity == NULL)
        return NULL;
    return get_script_fromactual(entity, sname);
}

void toggle_script_fromactual(entity_t *entity, char *sname, toggle_t toggle)
{
    script_t *script = get_script_fromactual(entity, sname);

    if (script == NULL)
        return;
    script->toggle = toggle;
}

void toggle_script_fromlist(entity_t *list, char *ename,
char *sname ,toggle_t toggle)
{
    script_t *script = get_script_fromlist(list, ename, sname);
    if (script == NULL)
        return;
    script->toggle = toggle;
}

void destroy_script_data(void **data)
{
    if (!(*data))
        free(*data);
}