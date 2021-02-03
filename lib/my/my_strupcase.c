/*
** EPITECH PROJECT, 2020
** Uppercase swapper
** File description:
** r
*/

char *my_strupcase(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return (0);
}
