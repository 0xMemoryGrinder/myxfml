/*
** EPITECH PROJECT, 2020
** script_utils.c
** File description:
** header for script_utils.c
*/

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

////////////////////////////////////////////////////////////////
      //TODO : TOGGLE SCRIPT AND SCRIPT LIST (TO MOVE !)
////////////////////////////////////////////////////////////////
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



////////////////////////////////////////////
            //TODO: MOVE IT !!
///////////////////////////////////////////

void toggle_collider_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_COLLIDER == NULL)
        return;
    E_COLLIDER->toggle = toggle;
}

void toggle_rendersprite_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_RSPRITE == NULL)
        return;
    E_RSPRITE->toggle = toggle;
}





// TOGGLE TRANSFORM
void toggle_transform_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_TRANSFORM == NULL)
        return;
    E_TRANSFORM->toggle = toggle;
}
// END OF TOGGLE TRANSFROM
