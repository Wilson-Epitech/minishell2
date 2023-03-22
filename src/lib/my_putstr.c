/*
** MINISHELL2 PROJECT, 2022
** day04
** File description:
** task02
*/
#include "../../includes/lib.h"

int my_putstr(char const *str)
{
    write (1, str, my_strlen(str));
}
