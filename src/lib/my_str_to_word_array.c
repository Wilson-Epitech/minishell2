/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_str_to_word_array_test
*/

#include "../../includes/lib.h"
#include <stdbool.h>

bool is_word_separator(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int count_i_nb_words(char const *str, int i)
{
    while (is_word_separator(str[i])) {
                i++;
    }
    return i;
}

int get_nb_words(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (is_word_separator(str[i])) {
            nb++;
            i = count_i_nb_words(str, i);
        } else {
            i++;
        }
    }
    return nb + 1;
}

int get_word_length(char const *str, int i)
{
    int count = 0;

    while (!is_word_separator(str[i]) && str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

char **my_str_to_word_array(char const *str)
{
    int word_length; int nb_words = get_nb_words(str);
    char **result = malloc(sizeof(char*) * (nb_words + 1));
    int i = 0; int x = 0; int y = 0;

    while (str[i] != '\0') {
        if (is_word_separator(str[i])) {
            i++;
        } else {
            word_length = get_word_length(str, i);
            result[x] = malloc(sizeof(char) * (word_length + 1));
            int y = 0;
            while (!is_word_separator(str[i]) && str[i] != '\0') {
                result[x][y] = str[i];
                i++; y++;
            }
            result[x][y] = '\0'; x++;
        }
    }
    result[x] = NULL; return result;
}
