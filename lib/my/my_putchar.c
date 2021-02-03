/*
** EPITECH PROJECT, 2020
** y
** File description:
** y
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
