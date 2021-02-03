/*
** EPITECH PROJECT, 2020
** Capitalizing char
** File description:
** r
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i;
    int bol = 0;

    my_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (i = 1; str[i] != '\0'; i++) {
        if (!( str[i - 1] >= 'a' && str[i - 1] <= 'z' ||
        str[i - 1] >= 'A' && str[i - 1] <= 'Z' ||
        str[i - 1] >= '0' && str[i - 1] <= '9'))
            bol = 1;
        if ( str[i] >= 'a' && str[i] <= 'z' && bol == 1)
            str[i] -= 32;
        bol = 0;
    }
    return (str);
}
