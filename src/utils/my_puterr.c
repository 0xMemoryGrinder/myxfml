/*
** EPITECH PROJECT, 2020
** my_puterr.c
** File description:
** my_puterr.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

void my_putstr_err(char *str);

void my_puterr(char *str)
{
    my_putstr_err(str);
    write(2, "\n", 1);
    exit(84);
}