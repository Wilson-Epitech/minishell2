/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_str_to_word_array_test
*/

#include "../../includes/lib.h"
#include <stdbool.h>

static int count_i_nb_words(char const *str, int i, char delim)
{
    while (is_word_separator_delim(str[i], delim)) {
                i++;
    }
    return i;
}

static int get_nb_words(char const *str, char delim)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (is_word_separator_delim(str[i], delim)) {
            nb++;
            i = count_i_nb_words(str, i, delim);
        } else {
            i++;
        }
    }
    return nb + 1;
}

static int get_word_length(char const *str, int i, char delim)
{
    int count = 0;

    while (!is_word_separator_delim(str[i], delim) && str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

static char *parse_word_delim(char const *str, char delim, int *i)
{
    int word_length = get_word_length(str, *i, delim);
    char *result = malloc(sizeof(char) * (word_length + 1));
    int y = 0;

    while (!is_word_separator_delim(str[*i], delim) && str[*i] != '\0') {
        result[y] = str[*i];
        (*i)++; y++;
    }
    result[y] = '\0'; return result;
}

char **my_str_to_word_array_delim(char const *str, char delim)
{
    int nb_words = get_nb_words(str, delim);
    char **result = malloc(sizeof(char*) * (nb_words + 1));
    int i = 0; int x = 0;

    while (str[i] != '\0') {
        if (is_word_separator_delim(str[i], delim)) {
            i++;
        } else {
            result[x] = parse_word_delim(str, delim, &i);
            x++;
        }
    }
    result[x] = NULL; return result;
}
