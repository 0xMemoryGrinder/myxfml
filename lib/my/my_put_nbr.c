/*
** EPITECH PROJECT, 2020
** nbr
** File description:
** dsq
*/

void my_putchar(char c);

void rev(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    if ( nb == -2147483648) {
        rev();
        return (0);
    }
    if ( nb >= 10 ) {
        my_put_nbr(nb /10);
    }
    else if ( nb < 0 ) {
        nb = nb * (-1);
        my_putchar('-');
        if ( nb > 9)
            my_put_nbr(nb /10);
    }
    my_putchar(nb % 10 + 48);
    return (0);
}
