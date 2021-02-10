/*
** EPITECH PROJECT, 2020
** events.h
** File description:
** header for events.c
*/

#ifndef LIBCSFML_EVENTS_H
#define LIBCSFML_EVENTS_H

#include "../types.h"

struct events_action_s{
    sfEventType type;
    void *(* action)(game_data_t *data);
    struct events_action_s *next;
};

#endif //LIBCSFML_EVENTS_H
