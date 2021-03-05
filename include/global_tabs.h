/*
** EPITECH PROJECT, 2020
** global_tabs.h
** File description:
** header for global_tabs.c
*/

#ifndef LIB_MYCSFML_GLOBAL_TABS_H
#define LIB_MYCSFML_GLOBAL_TABS_H

#include "types.h"
#include "custom_structs.h"
#include "custom.h"
#include "my.h"

typedef struct global_enum_tab_s {
    char *str;
    int enum_nb;
} global_enum_tab_t;

struct global_func_ptr_tab_s {
    char *str;
    void *(*func_ptr)();
};

static const global_enum_tab_t entity_type_enum_tab[] = {
        //
        //  entity_type
        //
        {"MOB", MOB},
        {"PNJ", PNJ},
        {"PLAYER", PLAYER},
        {"WALL", WALL},
        {"TOWER", TOWER},
        {"MAP", MAP},
        {"ROUTE",ROUTE},
};

static const global_enum_tab_t anim_type_enum_tab[] = {
        //
        // anim_type
        //
        {"IDLE",      IDLE},
        {"ATTACK",    ATTACK},
        {"DEFENSE",   DEFENSE},
        {"MOVING",    MOVING},
        {"HURT",      HURT},
        {"DEAD",      DEAD},
        {"DYING",     DYING},
        {"HOVER",     HOVER},
        {"CLICK",     CLICK},
        {"CUT_SCENE", CUT_SCENE},
        {NULL, 0}
};

static const global_enum_tab_t anim_enum_tab[] = {
        //
        // anim
        //
        {"DEFAULT", DEFAULT},


        // attacks
        {"ATTACK_SWORD", ATTACK_SWORD},
        {"ATTACK_RIGHT", ATTACK_RIGHT},
        {"ATTACK_LEFT", ATTACK_LEFT},
        {"ATTACK_HAMMER", ATTACK_HAMMER},
        {"ATTACK_BOW", ATTACK_BOW},
        {"ATTACK_MAGIC", ATTACK_MAGIC},
        {"ATTACK_MELEE", ATTACK_MELEE},
        {"ATTACK_DASH", ATTACK_DASH},
        {"ATTACK_CIRCLE", ATTACK_CIRCLE},
        {"ATTACK_BACKSTAB", ATTACK_BACKSTAB},

        // Defense
        {"DEFENSE_SHIELD", DEFENSE_SHIELD},
        {"DEFENSE_BODY", DEFENSE_BODY},
        {"DEFENSE_AVOID_LEFT", DEFENSE_AVOID_LEFT},
        {"DEFENSE_AVOID_RIGHT", DEFENSE_AVOID_RIGHT},
        {"DEFENSE_AVOID_TOP", DEFENSE_AVOID_TOP},
        {"DEFENSE_AVOID_BOTTOM", DEFENSE_AVOID_BOTTOM},

        // hurt
        {"HURT_PHYSIC", HURT_PHYSIC},
        {"HURT_KNOCKBACK", HURT_KNOCKBACK},

        // idle
        {"IDLE_STATIC", IDLE_STATIC},
        {"IDLE_TALK", IDLE_TALK},
        {"IDLE_BORED", IDLE_BORED},

        // move
        {"MOVING_WALK", MOVING_WALK},
        {"MOVING_RUN", MOVING_RUN},
        {"MOVING_DASH", MOVING_DASH},
        {"MOVING_CLIMB", MOVING_CLIMB},
        {"WALK_DOWN", WALK_DOWN},
        {"WALK_LEFT", WALK_LEFT},
        {"WALK_RIGHT", WALK_RIGHT},
        {"WALK_TOP", WALK_TOP},

        // mouse
        {"HOVER_ON", HOVER_ON},
        {"HOVER_OFF", HOVER_OFF},
        {"CLICK_ON", CLICK_ON},
        {"CLICK_OFF", CLICK_OFF},

        // dying
        {"DYING_BURNED", DYING_BURNED},
        {"DYING_FREEZED", DYING_FREEZED},
        {"DYING_EXPLODING", DYING_EXPLODING},
        {"DYING_SLICED", DYING_SLICED},
        {"DYING_MELTED", DYING_MELTED},

        // specials
        {"SPAWNING", SPAWNING},
        {"TALKING", TALKING},

        {NULL, 0}
};

static const struct global_func_ptr_tab_s scripts_func_ptr_tab[] = {
        {"my_putchar", (void *(*)())&my_putchar},
        {"tower_attack_script", (void *(*)()) &tower_attack_script},
        {"hoover_rs_script", (void *(*)()) &hoover_rs_script},
        {"mob_route_script", (void *(*)()) &mob_route_script},
        {"next_route", (void *(*)()) &next_route},
        {"health_stats_script", (void *(*)()) &health_stats_script},
        {"attack_stats_script", (void *(*)()) &attack_stats_script},
        {"wave_control_script", (void *(*)()) &wave_control_script},
        {"set_buildmenu_script", (void *(*)()) &set_buildmenu_script},
        {"on_sign_click", (void *(*)()) &on_sign_click},
        {"walking_direction_script",
        (void *(*)()) &walking_direction_script},
        {NULL, NULL}
};

static const struct global_func_ptr_tab_s destroy_sdata_func_ptr_tab[] = {
        {"my_putchar", (void *(*)())&my_putchar},
        {"destroy_script_data", (void *(*)()) &destroy_script_data},
        {NULL, NULL}
};

static const struct global_func_ptr_tab_s destroy_entity_func_ptr_tab[] = {
        {"my_putchar", (void *(*)()) &my_putchar},
        {NULL, NULL}
};

static const struct global_func_ptr_tab_s collider_func_ptr_tab[] = {
        {"my_putchar", (void *(*)()) &my_putchar},
        {"inject_next_route", (void *(*)()) &inject_next_route},
        {NULL, NULL}
};

static const struct global_func_ptr_tab_s anim_func_ptr_tab[] = {
        {"my_putchar", (void *(*)()) &my_putchar},
        {NULL, NULL}
};

#endif //LIB_MYCSFML_GLOBAL_TABS_H
