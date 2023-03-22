/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** print_env
*/

#include "../includes/lib.h"

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}
