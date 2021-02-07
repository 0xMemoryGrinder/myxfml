/*
** EPITECH PROJECT, 2020
** base_components.h
** File description:
** header for base_components.c
*/

#ifndef LIBCSFML_BASE_COMPONENTS_H
#define LIBCSFML_BASE_COMPONENTS_H

#include "../types.h"

        ////////////////////////////////
        //      BASE COMPONENTS       //
        ////////////////////////////////

//
//  Collider_Component
//
struct collider_s{
    toggle_t toggle;
    toggle_t is_rs_linked;
    sfVector2f position;
    sfVector2f dimensions;
    void (* on_collison)(entity_list_t *self, entity_list_t *collider,
    game_data_t *data, sfIntRect intersect);
};



//
//  RenderSprite_Component
//
struct render_sprite_s {
    toggle_t toggle;
    sfSprite *sprite;
    sfTexture *texture;
};



//
//  Transform_Component
//
struct transform_s {
    sfVector2f position;
    sfVector2f scale;
    sfVector2f velocity;
};



//
// Sound_component
//
struct sound_s{
    char *name;
    anim type;
    sfSound *sfx;
    sfSoundBuffer *buff;
    sfInt64 actual;
    sfInt64 trigger;
};

struct sfx_list_s{
    toggle_t toggle;
    sound_t *sfx;
    int sfx_count;
};



//
// Text_component
//
struct text_s{
    toggle_t toggle;
    sfText *text;
    sfFont *font;
    char *string;
    int size;
    sfVector2f pos;
};

struct texts_s{
    toggle_t toggle;
    text_t *text;
    int count;
};



//
//  Interact_component
//
struct interact_s{
    toggle_t toggle;
    toggle_t click;
    toggle_t hoover;
    toggle_t key;
    void (* click_action)(entity_list_t *e, game_data_t *d, animation_t *);
    void (* hoover_action)(entity_list_t *e, game_data_t *d, animation_t *);
    void (* key_action)(entity_list_t *e, game_data_t *d, animation_t *);
};



//
//  Animation_component
//
struct animation_s{
    toggle_t toggle;
    int actual_frame;
    anim_type type;
    anim_t *list;
    anim_t *actual;
};

struct anim_s{
    toggle_t toggle;
    int frames_count;
    anim name;
    sfInt64 actual_time;
    frame_t *frame;
    void (* frame_action)(game_data_t *d, entity_list_t *e, animation_t *a);
    anim_t *next;
};

struct frame_s{
    sfIntRect crop;
    sfInt64 trigger;
};



//
//  Script Component
//
struct script_s{
    toggle_t toggle;
    toggle_t time_dependent;
    sfInt64 trigger;
    sfInt64 actual;
    char *name;
    void *data;
    void *(*update)(void **d, game_data_t *g, entity_list_t *e);
    script_t *next;
};

struct script_list_s{
    toggle_t toggle;
    script_t *list;
    int count;
};





//
//  free components
//
void free_scripts(script_t *scripts);
void free_script_list(script_list_t *scripts);
void free_text(texts_t *texts);
void free_rendersprite(render_sprite_t *render);
void free_sound_list(sfx_list_t *sounds);
void free_anim_list(anim_t *animation);
void free_animation(animation_t *animation);



//
//  create components
//
components_t *malloc_components(void);

render_sprite_t *malloc_rendersprite(void);
transform_t *malloc_transform(void);
script_list_t *malloc_script_list(void);
interact_t *malloc_interact(void);
collider_t *malloc_collider(void);
animation_t *malloc_animations(void);
sfx_list_t *malloc_sfx_list(void);
texts_t *malloc_text_struct(void);




sound_t *malloc_sfx_array(int size);

script_t *malloc_script_node(void);

frame_t *malloc_frames_array(int count);
anim_t *malloc_anim_frame(void);

text_t *malloc_text_array(int size);






//  Script Initialization Exemple
//

/*
typedef struct attack_stats attact_stats_t;
typedef struct defense_stats defense_stats_t;
typedef struct support_stats support_stats_t;
typedef struct crowd_control_control crowd_control_t;

typedef struct ability_s ability_t;
typedef enum ability_typ {MAGIC_ATTACK}ability_type;
// donnee type
struct ability_s{
    ability_type type;
    attact_stats_t *attack;
    defense_stats_t *defense;
    support_stats_t *support;
    crowd_control_t *cc_stats;
};
*/


#endif //LIBCSFML_BASE_COMPONENTS_H
