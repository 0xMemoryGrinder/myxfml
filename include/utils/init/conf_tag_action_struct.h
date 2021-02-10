/*
** EPITECH PROJECT, 2020
** conf_tag_action_struct.h
** File description:
** header for conf_tag_action_struct.c
*/

#ifndef LIB_MYCSFML_CONF_TAG_ACTION_STRUCT_H
#define LIB_MYCSFML_CONF_TAG_ACTION_STRUCT_H

struct conf_tag_action_s {
    char *tag;
    int tag_len;
    void *(*action)();
};

#endif //LIB_MYCSFML_CONF_TAG_ACTION_STRUCT_H
