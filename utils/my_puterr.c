/*
** EPITECH PROJECT, 2020
** my_puterr.c
** File description:
** my_puterr.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_puterr.h"
#include "my.h"

void my_putstr_err(char *str);

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

int my_put_nbr_err(int nb)
{
    if ( nb >= 10 ) {
        my_put_nbr_err(nb /10);
    }
    else if ( nb < 0 ) {
        nb = nb * (-1);
        my_putchar_err('-');
        if ( nb > 9)
            my_put_nbr_err(nb /10);
    }
    my_putchar_err(nb % 10 + 48);
    return (0);
}

error_code_t my_puterr(char *str, char *filename, int line)
{
    my_putstr_err(str);
    my_putstr_err(" in ");
    my_putstr_err(filename);
    my_putstr_err(" at line ");
    my_put_nbr_err(line);
    write(2, "\n", 1);
    return error_code;
}