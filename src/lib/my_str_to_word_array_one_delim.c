/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_str_to_word_array_one_delim
*/

/*
** MINISHELL2 PROJECT, 2022
** bsbsq
** File description:
** my_str_to_word_array
*/

#include "../../includes/lib.h"

int strlencustom(char const *str, char delim)
{
    int i = 0;
    int nb = 0;

    while (str[i + 1] != '\0') {
        if (str[i + 1] == delim) {
            nb++;
        }
        i++;
    }
    return nb + 1;
}

char **word_array(char **result, char const *str, char delim)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == delim) {
            result[x][y] = '\0';
            x++;
            y = 0;
        } else {
            result[x][y] = str[i];
            y++;
        }
        i++;
    }
    result[x][y] = '\0';
    result[x + 1] = NULL;
    return result;
}

char **my_str_to_word_array_one_delim(char const *str, char delim)
{
    int i = 0;
    int count = 0;
    int nb = strlencustom(str, delim);
    int x = 0;
    char **result = malloc(sizeof(char*) * (nb + 1));

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            result[x] = malloc(sizeof(char) * (count + 1));
            x++;
            count = 0;
        } else
            count ++;
        i++;
    }
    result[x] = malloc(sizeof(char) * (count + 1));
    result = word_array(result, str, delim);
    return result;
}
