/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_strcat
*/

#include "../../includes/lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int n = 0;

    while (src[n] != '\0') {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[i] = '\0';
    return dest;
}
