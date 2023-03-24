/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_str_to_word_array_test
*/

#include "../../includes/lib.h"
#include <stdbool.h>

static bool is_word_separator(char c, char delim)
{
    return c == delim;
}

static int count_i_nb_words(char const *str, int i, char delim)
{
    while (is_word_separator(str[i], delim)) {
                i++;
    }
    return i;
}

static int get_nb_words(char const *str, char delim)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (is_word_separator(str[i], delim)) {
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

    while (!is_word_separator(str[i], delim) && str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

char **my_str_to_word_array_delim(char const *str, char delim)
{
    int word_length; int nb_words = get_nb_words(str, delim);
    char **result = malloc(sizeof(char*) * (nb_words + 1));
    int i = 0; int x = 0; int y = 0;

    while (str[i] != '\0') {
        if (is_word_separator(str[i], delim)) {
            i++;
        } else {
            word_length = get_word_length(str, i, delim);
            result[x] = malloc(sizeof(char) * (word_length + 1));
            int y = 0;
            while (!is_word_separator(str[i], delim) && str[i] != '\0') {
                result[x][y] = str[i];
                i++; y++;
            }
            result[x][y] = '\0'; x++;
        }
    }
    result[x] = NULL; return result;
}
