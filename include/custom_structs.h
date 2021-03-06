/*
** EPITECH PROJECT, 2020
** custom_structs.h
** File description:
** header
*/

#ifndef MY_DEFENDER_CUSTOM_STRUCTS_H
#define MY_DEFENDER_CUSTOM_STRUCTS_H

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "types.h"

typedef enum {
    LEVEL_1, SCENE_2, SCENE_3, SCENE_4
} scene_id;

enum entity_id_e{MOB, PNJ, PLAYER, WALL, TOWER, MAP, ROUTE, PROJECTILE};

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


// side enum
enum {
    UP, DOWN, RIGHT, LEFT,
};


//************************ MOB ROUTE ******************************//

static const sfVector2f routeslvl_1[] = {
        {72, 0},
        {72, 435},
        {435,420},
        {427, 206},
        {655, 221},
        {647, 480},
        {930, 471},
        {920, -15}
};

typedef struct td_route_s {
    const sfVector2f *routes;
    int route_count;
}td_route_t;

static const td_route_t td_routes[] = {
        [LEVEL_1] = {routeslvl_1, 8},
};

typedef struct mob_route_s {
    sfVector2f target;
    int checkpoints_passed;
    int distance_fromcastle;
}mob_route_t;

typedef struct next_route_sdata_s {
    sfVector2f next_pos;
    int route_nb;
} next_route_sdata_t;
//*********************** END MOB ROUTE ***************************//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//*********************** RP Component's **************************//

typedef enum projectile_type_s {ARROW, BOMB} projectile_type_t;

typedef struct projectile_s projectile_t;

struct projectile_s {
    int damage;
    entity_t *target;
    sfVector2f target_center;
};


typedef struct health_stats_s {
    float health;
    float max_health;
    sfRectangleShape *life;
    sfRectangleShape *total_life;
} health_stats_t;

typedef struct attack_stats_s {
    int damage;
    float attack_speed;
    float range;
    toggle_t is_attacking;
} attack_stats_t;

typedef struct aggro_data_s{
    entity_list_t *aggro_list;
    entity_t *aggro_entity;
    toggle_t is_aggro;
} aggro_data_t;


//*********************** END RP Component's **********************//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//*********************** TD Component's **************************//

typedef struct wave_s {
    sfInt64 between;
    sfInt64 actual_time;
    entity_list_t *to_spawn;
    entity_list_t *list;
} wave_t;

typedef struct level_waves_s {
    int count;
    int actual;
    sfInt64 between;
    sfInt64 actual_time;
    sfBool wave_done;
    wave_t *waves;
    sfVector2f start;
} level_waves_t;


typedef struct tower_data_s {
    toggle_t is_targeting;
    toggle_t is_attacking;
    entity_list_t *targets;
    entity_t *target;
    int level;
    int damage;
    int range;
    float attack_speed;
} tower_data_t;

//********************** END TD Component's ***********************//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//********************** Constants ********************************//

static const char *towers_stats_conf_filepath = "conf/towers_stats.xml";

#endif //MY_DEFENDER_CUSTOM_STRUCTS_H
