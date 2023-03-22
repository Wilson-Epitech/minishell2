/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** exit_command
*/

#include "../includes/lib.h"

int exit_command(char **args)
{
    char *str = "exit";
    if (my_strcmp(str, args[0]) == 0) {
        exit(0);
    }
    return 0;
}
