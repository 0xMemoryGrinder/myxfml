/*
** EPITECH PROJECT, 2020
** scene_scripts_loading.c
** File description:
** header for scene_scripts_loading.c
*/

#include "utils/init_xfml.h"
#include "my.h"
#include "my_csfml.h"
#include "my_puterr.h"


void set_script_toggle(char *content, int *i, script_t *script);
void set_script_time_dep(char *content, int *i, script_t *script);
void set_script_trigger(char *content, int *i, script_t *script);
void set_script_name(char *content, int *i, script_t *script);
void set_script_action(char *content, int *i, script_t *script);

static struct conf_tag_action_s scene_script_tags[] = {
        {"<toggle>", 8, (void *(*)()) &set_script_toggle},
        {"<name>", 6, (void *(*)()) &set_script_name},
        {"<time_dependent>", 16, (void *(*)()) &set_script_time_dep},
        {"<action>", 8, (void *(*)()) &set_script_action},
        {"<trigger>", 9, (void *(*)()) &set_script_trigger},
        {NULL, 0, NULL}
};

script_t *load_scene_script(char *content, int *i)
{
    script_t *script = malloc_script_node();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</script>", 9)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (scene_script_tags[k].tag && my_strncmp(content + *i,
        scene_script_tags[k].tag, scene_script_tags[k].tag_len))
            k++;
        if (!scene_script_tags[k].tag)
            my_puterr("Unrecognized script tag", __FILE__, __LINE__);
        *i += scene_script_tags[k].tag_len;
        scene_script_tags[k].action(content, i, script);
        *i += scene_script_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
    return script;
}

void load_scene_scripts_list(char *content, int *i, script_list_t *scripts)
{
    scripts->count = my_getnbr(content + *i);
    script_t *current = scripts->list;

    for (int n = 0; n < scripts->count; n++) {
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
        *i += 1;
        skip_to_next_tag(content, i, OPEN);
        if (n == 0) {
            scripts->list = load_scene_script(content, i);
            current = scripts->list;
        } else {
            current->next = load_scene_script(content, i);
            current = current->next;
        }
        skip_to_next_tag(content, i, CLOSE);
    }
    *i += 1;
    skip_to_next_tag(content, i, CLOSE);
}

static struct conf_tag_action_s scene_scripts_tags[] = {
        {"<toggle>", 8, (void *(*)()) &set_script_toggle},
        {"<list count=\"", 13, (void *(*)()) &load_scene_scripts_list},
        {NULL, 0, NULL}
};

void load_scene_scripts(char *content, int *i, 
scene_id id, game_data_t *data)
{
    data->scenes->list[id].scene_scripts = malloc_script_list();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</scripts>", 8)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (scene_scripts_tags[k].tag && my_strncmp(content + *i,
        scene_scripts_tags[k].tag, scene_scripts_tags[k].tag_len))
            k++;
        if (!scene_scripts_tags[k].tag)
            my_puterr("Unrecognized scene scripts tag", __FILE__, __LINE__);
        *i += scene_scripts_tags[k].tag_len;
        scene_scripts_tags[k].action(content, i,
        data->scenes->list[id].scene_scripts);
        if (k == 1)
            *i += 7;
        else
            *i += scene_script_tags[k].tag_len + 1;
        skip_to_next_tag(content, i, NEXT);
    }
}