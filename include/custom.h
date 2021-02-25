/*
** EPITECH PROJECT, 2020
** my_types.h
** File description:
** header for my_types.c
*/

#ifndef MY_DEFENDER_CUSTOM_H
#define MY_DEFENDER_CUSTOM_H

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "types.h"

typedef enum {
    SCENE_1, SCENE_2, SCENE_3, SCENE_4
} scene_id;


enum entity_id_e{MOB, PNJ, PLAYER, WALL, TOWER, MAP, ROUTE};

typedef enum anim_type_e{
    IDLE, ATTACK, DEFENSE, MOVING, HURT,
    DEAD, DYING, HOVER, CLICK, CUT_SCENE
} anim_type;

typedef enum anim_e{
    //DEFAULT
    DEFAULT,

    //  ATTACKS
    ATTACK_SWORD, ATTACK_HAMMER ,ATTACK_BOW, ATTACK_MAGIC, ATTACK_MELEE,
    ATTACK_DASH, ATTACK_CIRCLE, ATTACK_BACKSTAB, ATTACK_RIGHT, ATTACK_LEFT,

    //  DEFENSE
    DEFENSE_SHIELD, DEFENSE_BODY, DEFENSE_AVOID_LEFT, DEFENSE_AVOID_RIGHT,
    DEFENSE_AVOID_TOP, DEFENSE_AVOID_BOTTOM,

    //  HURT
    HURT_PHYSIC, HURT_KNOCKBACK,

    //  IDLE
    IDLE_STATIC, IDLE_TALK, IDLE_BORED,

    //  MOVING
    MOVING_WALK, MOVING_RUN, MOVING_DASH, MOVING_CLIMB, WALK_RIGHT, WALK_LEFT, WALK_TOP, WALK_DOWN,

    //  HOOVER
    HOVER_ON, HOVER_OFF,

    //  CLICK
    CLICK_ON, CLICK_OFF,

    //  DYING
    DYING_BURNED, DYING_FREEZED, DYING_EXPLODING, DYING_SLICED, DYING_MELTED,

    // CUT_SCENE
    SPAWNING, TALKING,
} anim;



// TD Routes
typedef enum td_poin{START, END}td_point;

typedef struct td_route_s {
    sfVector2f* route;
}td_route_t;

static const sfVector2f routelvl_1[] = {
            {72, 0},
            {72, 435},
            {423,420},
            {423, 221},
            {647, 221},
            {647, 471},
            {919, 471},
            {920, 0}
};

// side enum
enum {
    UP, DOWN, RIGHT, LEFT,
};

// Projectile type

typedef enum projectile_type_s {ARROW, BOMB}projectile_type_t;
typedef struct projectile_s projectile_t;

struct projectile_s {
    int damage;
};

// tower type
typedef struct tower_data_s tower_data_t;

struct tower_data_s {
    toggle_t is_targeting;
    toggle_t is_attacking;
    entity_list_t *targets;
    sfVector2f target;
    int level;
    int damage;
    int range;
    float attack_speed;
};

#endif //MY_DEFENDER_CUSTOM_H
