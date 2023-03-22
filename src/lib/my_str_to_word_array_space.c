/*
** MINISHELL2 PROJECT, 2022
** bsbsq
** File description:
** my_str_to_word_array
*/

#include "../../includes/lib.h"

int strlencustom_space(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i + 1] != '\0') {
        if (str[i + 1] == '\n') {
            nb++;
        }
        i++;
    }
    return nb + 1;
}

char **word_array_space(char **result, char const *str)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
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

char **my_str_to_word_array_space(char const *str)
{
    int i = 0;
    int count = 0;
    int nb = strlencustom_space(str);
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
    result = word_array_space(result, str);
    return result;
}
