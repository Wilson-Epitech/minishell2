/*
** MINISHELL2 PROJECT, 2022
** bsq
** File description:
** my_getnbr
*/

#include "../../includes/lib.h"

static int my_getreturn(char const *str, int i, int nb)
{
    if (str[i] < '0' || str[i] > '9') {
        return (nb);
    }
}

int my_getnbr(char const *str)
{
    int i = 0; int nb = 0;
    int sign = 1;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            my_getreturn(str, i, nb);
        }
        i++;
    }
    if (sign == -1) {
        return sign * nb;
    } else {
        return nb;
    }
}
