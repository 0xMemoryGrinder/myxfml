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





// TOGGLE TRANSFORM
void toggle_transform_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_TRANSFORM == NULL)
        return;
    E_TRANSFORM->toggle = toggle;
}
// END OF TOGGLE TRANSFROM





// TOGGLE SOUND
// TODO : TOGGLE FOR SPECIFIC SOUND
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
// END OF TOGGLE SOUND





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

// END OFF TEXT TOGGLE









//  TOGGLE AND UPDATE ANIMATION
// TODO : TOGGLE FOR SPECIFIC ANIM
void toggle_animlist_fromlist(entity_t *list, char *name, toggle_t toggle)
{
    entity_t *entity = get_entity_name(list, name);

    if (entity == NULL || E_ANIMATION == NULL)
        return;
    E_ANIMATION->toggle = toggle;
}

void change_anim_fromactual(entity_t *entity, anim name, anim_type type)
{
    E_ANIMATION->actual_anim = name;
    if (type != -1)
        E_ANIMATION->type = type;
    update_anim_state(entity);
}

void change_anim_fromlist(entity_t *list, char *ename,
anim name, anim_type type)
{
    entity_t *entity = get_entity_name(list, ename);

    if (entity == NULL)
        return;
    change_anim_fromactual(entity, name, type);
}
// END OF ANIMATION UPDATE