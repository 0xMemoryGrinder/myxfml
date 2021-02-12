/*
** EPITECH PROJECT, 2020
** script_utils.c
** File description:
** header for script_utils.c
*/

#include "../../../include/my_csfml.h"
#include "../../../include/my.h"

script_t *get_script_from_actual(entity_t *entity, char *name)
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

script_t *get_script_from_elist(entity_t *list, char *ename, char *sname)
{
    entity_t *entity = get_entity_name(list, ename);

    if (entity == NULL)
        return NULL;
    return get_script_from_actual(entity, sname);
}

void *get_entity_script_data_fromlist(entity_t *entity,
char *ename, char *sname)
{
    script_t *script = get_script_from_elist(entity, ename, sname);

    if (script == NULL)
        return NULL;
    return script->data;
}

void *get_script_data_fromactual(entity_t *entity, char *sname)
{
    script_t *script = get_script_from_actual(entity, sname);

    if (script == NULL)
        return NULL;
    return script->data;
}

////////////////////////////////////////////////////////////////
      //TODO : TOGGLE SCRIPT AND SCRIPT LIST (TO MOVE !)
////////////////////////////////////////////////////////////////
void toggle_script_fromactual(entity_t *entity, char *sname, toggle_t toggle)
{
    script_t *script = get_script_from_actual(entity, sname);

    if (script == NULL)
        return;
    script->toggle = toggle;
}

void toggle_entity_script(entity_t *list, char *ename,
char *sname ,toggle_t toggle)
{
    script_t *script = get_script_from_elist(list, ename, sname);
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

void toggle_transform_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_TRANSFORM == NULL)
        return;
    E_TRANSFORM->toggle = toggle;
}

// TODO : TOGGLE FOR SPECIFIC SOUND
void toggle_sfxlist_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_SOUND == NULL)
        return;
    E_SOUND->toggle = toggle;
}

// TODO : TOGGLE FOR SPECIFIC TEXT
void toggle_textlist_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_TEXT == NULL)
        return;
    E_TEXT->toggle = toggle;
}

// TODO : TOGGLE FOR SPECIFIC ANIM
void toggle_animlist_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_ANIMATION == NULL)
        return;
    E_ANIMATION->toggle = toggle;
}

