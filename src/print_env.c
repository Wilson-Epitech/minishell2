/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** print_env
*/

#include "../includes/lib.h"

void print_env(char **args, char **env)
{
    if (my_strcmp(args[0], "env") == 0) {
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
    }
}
