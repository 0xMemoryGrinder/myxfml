/*
** EPITECH PROJECT, 2019
** my
** File description:
** eader file that contains the prototypes of all the functions
*/

int char_condition(char const *str, int i);
void mod_strncpy(char *tab, char const *str, int i, int char_count);
int word_counting(char const *str, int i);
int char_counting(const char *str, int i);
char **my_str_to_word_array(char const *str);
int check_int(char const *str, int nSize, int nb);
int my_showmem(char const *str, int size);
int my_str_isupper(char const *str);
int my_compute_power_rec(int nb, int power);
int my_showstr(char const *str);
int my_strlen(char const *str);
int my_compute_square_root(int nb);
void my_sort_int_array(int *tab, int size);
char *my_strlowcase(char *str);
int my_getnbr(char const *str);
char *my_strcapitalize(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_isneg (int nb);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_is_prime(int nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
int my_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strstr(char *str, char const *to_find);
void my_putchar(char c);
int my_str_isalpha(char const *str);
char *my_strupcase(char *str);
int my_put_nbr(int nb);
int my_str_islower(char const *str);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_str_isnum(char const *str);
char *my_revstr (char *str);
int my_str_isprintable(char const *str);
char **str_to_tab(char *str, const char separator);
char *my_realloc(char *src);

void my_putstr_err(char *str);
char *my_strndup(char *str, int n);
char **my_str_to_tab(const char *str, char separator);
float my_getnbr_f(char *str);