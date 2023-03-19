/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_strncmp
*/

#include <stdio.h>

int my_strncmp(char const *str1, char const *str2, int size)
{
    int i = 0;
    while (i < size && str1[i] != '\0' && str2[i] != '\0'
        && str1[i] == str2[i]) {
        i++;
    }
    if (i == size) {
        return 0;
    }
    if (str1[i] < str2[i]) {
        return -1;
    } else {
        return 1;
    }
}
