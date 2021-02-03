/*
** EPITECH PROJECT, 2020
** MY_STRCAT.C
** File description:
** concat two string
*/

int my_strlen_ncat(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char *my_strncat(char *dest , char  const *src, int nb)
{
    int dest_length = my_strlen_ncat(dest);

    for (int i = 0; i < nb && src[i] != '\0' ; i++, dest_length++) {
        dest[dest_length] = src[i];
    }
    dest[dest_length] = '\0';
    return dest;
}