/*
** EPITECH PROJECT, 2020
** MY_STRNCPY.C
** File description:
** copy n chars in another string
*/

int my_strlen_ncpy(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int length  = my_strlen_ncpy(src);
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (n > length)
        dest[i] = '\0';
    return dest;
}
