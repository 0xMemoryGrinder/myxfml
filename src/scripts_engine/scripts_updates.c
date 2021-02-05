/*
** EPITECH PROJECT, 2020
** scripts_updates.c
** File description:
** header for scripts_updates.c
*/

#include "../../include/my_csfml.h"
#include "../../include/types_and_base/entity.h"
#include "../../include/types_and_base/base_components.h"
#include "../../include/types_and_base/game.h"
#include "../../include/types_and_base/video.h"
#include "../../include/types_and_base/struct_shortcuts.h"
#include "../../include/types_and_base/clock.h"

void update_script(game_data_t *data, entity_list_t *entity, script_t *script)
{
    if (script->toggle == OFF || script->update == NULL)
        return;
    if (script->time_dependent == ON &&
    my_timer(G_CLOCK, script->trigger, &script->actual )) {
        script->update(script->data, data, entity);
    } else if (script->time_dependent == OFF) {
        script->update(script->data, data, entity);
    }
}

void get_scripts_updates(game_data_t *data, entity_list_t *list)
{
    entity_list_t *entities = list;
    script_t *scripts;

    for (; entities; entities = entities->next) {
        if (entities->E_SCRIPT->toggle == OFF)
            continue;
        scripts = entities->E_SCRIPT->list;
        for (; scripts; scripts = scripts->next) {
            update_script(data, entities, scripts);
        }
    }
}