/*
** EPITECH PROJECT, 2020
** init_xfml.h
** File description:
** header for init_xfml.c
*/

#ifndef LIBCSFML_INIT_XFML_H
#define LIBCSFML_INIT_XFML_H


#include "init/load_file.h"
#include "init/conf_tag_action_struct.h"
#include "init/common_tags.h"

#include "init/entity/load_entity.h"
#include "init/entity/set_entity_properties.h"


#include "init/entity/components/load_components.h"

#include "init/entity/components/texts/load_texts_component.h"


entity_t *load_entity(char *filepath, entity_t *parent);


//
//  GLOBAL INIT
//
static const struct conf_tag_action_s entity_tag = {"<entity>",8};

void insert_gui_entity(char *content, int *i,
scene_id id, game_data_t *data);
void insert_player_entity(char *content, int *i,
scene_id id, game_data_t *data);
void insert_global_entity(char *content, int *i,
scene_id id, game_data_t *data);

static const struct conf_tag_action_s insert_conf_tags[]= {
        {"<globals>",9, (void *(*)()) &insert_global_entity},
        {"<gui>",5, (void *(*)()) &insert_gui_entity},
        {"<player>",8, (void *(*)()) &insert_player_entity},
        {NULL}

};

void insert_globals_in_scene(char *content, int *i,
scene_id id ,game_data_t *data);

void get_global_entities(char *content, int *i, game_data_t *data);
void get_player_entities(char *content, int *i, game_data_t *data);
void get_gui_entities(char *content, int *i, game_data_t *data);





//
//  Main SCENE SETTINGS
//
void get_scene_name(char *content, int *i, scene_id id, game_data_t *data);
void get_scene_toggle(char *content, int *i, scene_id id, game_data_t *data);
void get_scene_background(char *content, int *i,
scene_id id, game_data_t *data);
void init_entities_list(char *content, int *i, scene_id id, game_data_t *data);

static const struct conf_tag_action_s scene_tags[]= {
        {"<name>",6, (void *(*)()) &get_scene_name},
        {"<toggle>",8, (void *(*)()) &get_scene_toggle},
        {"<insert>",8, (void *(*)()) &insert_globals_in_scene},
        {"<scripts>",9 },//(void *(*)()) &get_scene_scripts},TODO !!!!!!
        {"<background>",12, (void *(*)()) &get_scene_background},
        {"<entities>",10, (void *(*)()) &init_entities_list},
        {NULL}
};

// Load Scene
void get_scene(char *content, int *i, game_data_t *data, scene_id id);
void load_scene(char *path, scene_id id, game_data_t *data);

void get_scenes_list(char *content, int *i, game_data_t *data);
void get_actual_scene_id(char *content, int *i, game_data_t *data);
void get_scenes_count(char *content, int *i, game_data_t *data);
void get_game_scenes(char *content, int *i, game_data_t *data);

static const struct conf_tag_action_s scene_conf_tags[]= {
        {"<actual>",8, (void *(*)()) &get_actual_scene_id},
        {"<count>",7, (void *(*)()) &get_scenes_count},
        {"<list>",6, (void *(*)()) &get_scenes_list},
        {NULL}
};



//
//  Load GAME SETTINGS
//
void get_canvas_size(char *content, int *i, game_data_t *data);

// VIDEO SETTINGS
void set_window_title(char *content, int *i, game_data_t *data);
void set_window_height(char *content, int *i, game_data_t *data);
void set_window_width(char *content, int *i, game_data_t *data);
void set_max_fps(char *content, int *i, game_data_t *data);
void get_fullscreen_toggle(char *content, int *i, game_data_t *data);

static const struct conf_tag_action_s video_conf_tags[]= {
        {"<game_title>",12, (void *(*)()) &set_window_title},
        {"<height>",8, (void *(*)()) &set_window_height},
        {"<width>",7, (void *(*)()) &set_window_width},
        {"<max_fps>",9, (void *(*)()) &set_max_fps},
        {"<fullscreen>",12, (void *(*)()) &get_fullscreen_toggle},
        {NULL}
};
void get_video_data(char *content, int *i, game_data_t *data);


// AUDIO SETTINGS
void set_music_volume(char *content, int *i, game_data_t *data);
void set_sfx_volume(char *content, int *i, game_data_t *data);
void get_music_count(char *content, int *i, game_data_t *data);
void set_actual_theme(char *content, int *i, game_data_t *data);
void get_music_array(char *content, int *i, game_data_t *data);

static const struct conf_tag_action_s audio_conf_tags[]= {
        {"<music_volume>",14, (void *(*)()) &set_music_volume},
        {"<sfx_volume>",12, (void *(*)()) &set_sfx_volume},
        {"<music_count>",13, (void *(*)()) &get_music_count},
        {"<actual_theme>",14, (void *(*)()) &set_actual_theme},
        {"<mslist>",8, (void *(*)()) &get_music_array},
        {NULL}
};

void get_audio_data(char *content, int *i, game_data_t *data);

static const struct conf_tag_action_s settings_conf_tags[]= {
        {"<video>",7, (void *(*)()) &get_video_data},
        {"<audio>",7, (void *(*)()) &get_audio_data},
        {NULL}
};

void get_settings(char *content, int *i, game_data_t *data);

static const struct conf_tag_action_s game_conf_tags[]= {
        {"<globals>",9, (void *(*)()) &get_global_entities},
        {"<gui>",5, (void *(*)()) &get_gui_entities},
        {"<player>",8, (void *(*)()) &get_player_entities},
        {"<scenes>",8, (void *(*)()) &get_game_scenes},
        {"<camera>",8, (void *(*)()) &get_canvas_size},
        {"<game_settings>",15, (void *(*)()) &get_settings},
        {NULL}
};


game_data_t *create_game(void);

#endif //LIBCSFML_INIT_XFML_H
