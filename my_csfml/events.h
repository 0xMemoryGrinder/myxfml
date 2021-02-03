/*
** EPITECH PROJECT, 2020
** events.h
** File description:
** header for events.c
*/

#ifndef LIBCSFML_EVENTS_H
#define LIBCSFML_EVENTS_H

#include "my_csfml.h"

struct events_action_s{
    sfEventType type;
    void *(* action)(game_data_t *data);
    struct events_action_s *next;
};

struct key_input_s{
    sfKeyCode key;
    void *(* action)(game_data_t *data);
};

#endif //LIBCSFML_EVENTS_H
