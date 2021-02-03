/*
** EPITECH PROJECT, 2020
** Compare n char
** File description:
** r
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int cmp = 0;
    int i;
    for (i = 0; s1[i] == s2[i] && i < n; i++)
    if (s1[i] > s2[i])
        cmp = s1[i] - s2[i];
    if (s1[i] < s2[i])
        cmp = ((s2[i] - s1[i]) * (-1));
    return (cmp);
}
