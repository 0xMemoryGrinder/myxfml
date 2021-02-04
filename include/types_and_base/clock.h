/*
** EPITECH PROJECT, 2020
** clock.h
** File description:
** header for clock.c
*/

#ifndef LIBCSFML_CLOCK_H
#define LIBCSFML_CLOCK_H

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>


//#include "src.h"

//
//  DEFINITON
//
#define SECONDS(seconds) (seconds * 1000000)

sfBool my_timer(sfClock *clock, int trigger, int *actual);

#endif //LIBCSFML_CLOCK_H
