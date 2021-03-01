/*
** EPITECH PROJECT, 2020
** my_puterr.h
** File description:
** header for my_puterr.c
*/

#ifndef LIB_MYCSFML_MY_PUTERR_H
#define LIB_MYCSFML_MY_PUTERR_H

typedef union error_code_u {
    int nb;
    void *ptr;
}error_code_t;

static const error_code_t error_code = {0};

error_code_t my_puterr(char *str,  char *filename, int line);

#endif //LIB_MYCSFML_MY_PUTERR_H
