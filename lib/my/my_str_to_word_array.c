/*
** EPITECH PROJECT, 2020
** y
** File description:
** y
*/

#include <stdlib.h>

int char_condition(char const *str, int i)
{
    int bol = 0;

    if (!(str[i + 1] <= 'z' && str[i + 1] >= 'a' ||
    str[i + 1] <= '9' && str[i + 1] >= '0' ||
    str[i + 1] <= 'Z' && str[i + 1] >= 'A'))
        bol = 1;
    return bol;
}

void mod_strncpy(char *tab, char const *str, int i, int char_count)
{
    int j = 0;
    int stop = char_count;

    for (; char_count > 0; char_count--, j++) {
        tab[j] = str[i - char_count];
    }
    tab[stop] = '\0';
}
int word_counting(char const *str, int i)
{
    int w_ct =0;

    if (!(str[i + 1] <= 'z' && str[i + 1] >= 'a' ||
    str[i + 1] <= '9' && str[i + 1] >= '0' ||
    str[i + 1] <= 'Z' && str[i + 1] >= 'A')) {
        w_ct = 1;
    }
    return(w_ct);
}

int char_counting(const char *str, int i)
{
    int c_ct = 0;
    int bol = 0;

    for (; bol == 0; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' ||
        str[i] >= '0' && str[i] <= '9' ||
        str[i] >= 'A' && str[i] <= 'Z') {
            bol = char_condition(str, i);
            c_ct++;
        }
    }
    return (c_ct);
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int word_count = 1;
    int char_count;
    int j = 0;

    for (int i = 0; str[i] != '\0' ; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' ||
        str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'Z')
            word_count += word_counting(str, i);
    }
    tab = malloc(sizeof(char *) * word_count);
    for (int i = 0; str[i] != '\0'; i++, char_count = 0) {
        if (str[i] >= 'a' && str[i] <= 'z' ||
            str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'Z') {
            char_count = (char_counting(str, i));
            i += (char_count);
            tab[j] = malloc(sizeof(char) * (char_count + 1));
            mod_strncpy(tab[j], str, i, char_count);
            j++;
        }
    }
    tab[word_count - 1] = NULL;
    return (tab);
}

int my_strncpy(char *, char *, int n);

int separator_count(const char *str, const char separator)
{
    int i = 0;
    int count = 0;

    for (; str[i]; i++) {
        if (str[i] == separator) {
            count++;
        }
    }
    return count;
}

int lenght_until_sep(char const *str, const char separator, int i)
{
    int count = 0;

    for (; str[i] != separator; count++, i++);
    return count;
}

char **str_to_tab(char *str, const char separator)
{
    int cases = separator_count(str, separator);
    char **tab = malloc(sizeof(char *) * cases);
    int line_lenght = 0;

    for (int i = 0; tab[i]; i++) {
        line_lenght = lenght_until_sep(str, separator, i);
        tab[i] = malloc(sizeof(char) * line_lenght);
        my_strncpy(tab[i], str, line_lenght);
        str += line_lenght;
    }
    return tab;
}