/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_strdup
*/

#include "../../includes/lib.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);;
    int i = 0;

    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
