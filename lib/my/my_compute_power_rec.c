/*
** EPITECH PROJECT, 2020
** power rec
** File description:
** recursivity power
*/

int my_compute_power_rec(int nb, int p)
{
    if (p <= 0) {
        if (p < 0)
            return (0);
        else
            return (1);
    }
    else if (p > 1)
        nb = nb * (my_compute_power_rec(nb, (p - 1)));
    if (nb > 2147483647)
        return (0);
    else
        return (nb);
}
