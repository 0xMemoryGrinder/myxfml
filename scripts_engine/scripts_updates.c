/*
** EPITECH PROJECT, 2020
** scripts_updates.c
** File description:
** header for scripts_updates.c
*/

#include "my_csfml.h"

int update_script(game_data_t *data, entity_list_t *entity, script_t *script)
{
    if (script->toggle == OFF || script->update == NULL)
        return - 1;
    else if (script->time_dependent == ON &&
    my_timer(G_CLOCK, script->trigger, &script->actual ))
        return script->update(&(script->data), data, entity->entity);
    if (script->time_dependent == OFF && entity)
        return script->update(&script->data, data, entity->entity);
    else if (script->time_dependent == OFF && !entity)
        return script->update(&script->data, data, NULL);
    return 1;
}

int get_scripts_updates(game_data_t *data, entity_list_t *list)
{
    entity_list_t *entities = list;
    script_t *scripts;
    int status = 1;

    for (; status && entities; entities = entities->next) {
        if (entities->entity->toggle == OFF
        || entities->E_SCRIPT->toggle == OFF)
            continue;
        scripts = entities->E_SCRIPT->list;
        for (; status && scripts; scripts = scripts->next) {
            status = update_script(data, entities, scripts);
        }
    }
    return status;
}