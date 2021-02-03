/*
** EPITECH PROJECT, 2020
** Search str
** File description:
** r
*/

int my_str_lenght(char const *to_find)
{
    int j;
    for (j = 0; to_find[j] != '\0'; j++);
    return (j);
}

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    int ln = my_str_lenght(to_find);

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == to_find[j]) {
            j++;
            i++;
            ln--;
            if (ln == 1) {
                return (str);
                }
        }
        str++;
        return (str);
    }
}
