/*
** EPITECH PROJECT, 2020
** my_csfml.h
** File description:
** header for my_csfml_lib
*/

#ifndef LIBCSFML_MY_CSFML_H
#define LIBCSFML_MY_CSFML_H

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

typedef enum {A, B, C, D, E} id;

typedef enum toggle_e{ON, OFF}toggle_t;

typedef enum anim_type_e{
    IDLE, ATTACK, DEFENSE, MOVING, HURT,
    DEAD, DYING, HOOVER, CLICK, CUT_SCENE
} anim_type;

typedef enum anim_e{
    //  ATTACKS
    ATTACK_SWORD, ATTACK_HAMMER ,ATTACK_BOW, ATTACK_MAGIC, ATTACK_MELEE,
    ATTACK_DASH, ATTACK_CIRCLE, ATTACK_BACKSTAB,

    //  DEFENSE
    DEFENSE_SHIELD, DEFENSE_BODY, DEFENSE_AVOID_LEFT, DEFENSE_AVOID_RIGHT,
    DEFENSE_AVOID_TOP, DEFENSE_AVOID_BOTTOM,

    //  HURT
    HURT_PHYISIC, HURT_KNOCKBACK,

    //  IDLE
    IDLE_STATIC, IDLE_TALK, IDLE_BORED,

    //  MOVING
    MOVING_WALK, MOVING_RUN, MOVING_DASH, MOVING_CLIMB,

    //  HOOVER
    HOOVER_ON, HOOVER_OFF,

    //  CLICK
    CLICK_ON, CLICK_OFF,

    //  DYING
    DYING_BURNED, DYING_FREEZED, DYING_EXPLODING, DYING_SLICED, DYING_MELTED,

    // CUT_SCENE
    SPAWNING, TALKING,
} anim;

//"ATTACK_SWORD", ATTACK_SWORD

//
//  COMPONENTS TYPES
//
typedef struct action_trigger_s action_trigger_t;
typedef struct collider_s collider_t;
typedef struct crop_s crop_t;
typedef struct render_sprite_s render_sprite_t;
typedef struct transform_s transform_t;
typedef struct sound_s sound_t;
typedef struct sfx_list_s sfx_list_t;
typedef struct text_s text_t;
typedef struct texts_s texts_t;
typedef struct interact_s interact_t;
typedef struct tag_s tag_t;
typedef struct tag_list_s tag_list_t;
typedef struct animation_s animation_t;
typedef struct anim_s anim_t;
typedef struct anim_trigger_s anim_trigger_t;
typedef struct script_s script_t;
typedef struct script_list_s script_list_t;



//
//  ENTITY TYPES
//
typedef struct entity_s entity_t;
typedef struct entity_list_s entity_list_t;
typedef struct components_s components_t;



//
//  MAIN GAME TYPES
//
typedef struct game_data_s game_data_t;
typedef struct global_stats_s global_stats_t;
typedef struct settings_s settings_t;
typedef struct game_stats_s game_stats_t;
typedef struct time_stats_s time_stats_t;
typedef struct camera_s camera_t;


//
//  EVENTS TYPES
//
typedef struct events_action_s events_action_t;
typedef struct key_input_s key_input_t;



//
//  SCENE TYPES
//
typedef struct scene_s scene_t;



//
//  VIDEO TYPES
//
typedef struct video_data_s video_data_t;



//
// AUDIO TYPES
//
typedef struct audio_data_s audio_data_t;
typedef struct music_s music_t;


#endif //LIBCSFML_MY_CSFML_H