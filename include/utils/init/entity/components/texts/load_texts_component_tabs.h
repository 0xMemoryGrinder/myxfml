/*
** EPITECH PROJECT, 2020
** load_texts_component_tabs.h
** File description:
** header for load_texts_component_tabs.c
*/

#ifndef LIB_MYCSFML_LOAD_TEXTS_COMPONENT_TABS_H
#define LIB_MYCSFML_LOAD_TEXTS_COMPONENT_TABS_H

#include <stdlib.h>
#include "utils/init/conf_tag_action_struct.h"
#include "utils/init/entity/components/texts/load_texts_component.h"
#include "my_csfml.h"

static struct conf_tag_action_s texts_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_texts_toggle},
        {"<list count=\"", 13, (void *(*)()) &load_texts_list},
        {NULL, 0, NULL}
};

static struct conf_tag_action_s text_conf_tag_action[] = {
        {"<id>", 4, (void *(*)()) &load_text_id},
        {"<toggle>", 8, (void *(*)()) &load_text_toggle},
        {"<rs_linked>", 11, (void *(*)()) &load_text_rs_linked},
        {"<path>", 6, (void *(*)()) &load_text_font},
        {"<position>", 10, (void *(*)()) &load_text_position},
        {"<offset>", 8, (void *(*)()) &load_text_offset},
        {"<font_size>", 11, (void *(*)()) &load_text_font_size},
        {"<string>", 8, (void *(*)()) &load_text_string},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_TEXTS_COMPONENT_TABS_H
