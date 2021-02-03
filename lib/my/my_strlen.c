/*
** EPITECH PROJECT, 2020
** y
** File description:
** y
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
