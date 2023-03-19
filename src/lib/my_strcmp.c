/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_strcmp
*/

#include "../../includes/lib.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'
        && str1[i] == str2[i]) {
        i++;
    }
    if (str1[i] == str2[i]) {
        return 0;
    }
    if (str1[i] < str2[i]) {
        return -1;
    } else {
        return 1;
    }
}
