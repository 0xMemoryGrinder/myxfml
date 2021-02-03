/*
** EPITECH PROJECT, 2020
** ifFunction
** File description:
** negativ or positiv condition
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if ( n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
