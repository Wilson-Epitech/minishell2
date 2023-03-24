/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** setenv_one_arg
*/

#include "../../includes/lib.h"

char **setenv_command_one_arg(char **args, char **env)
{
    char *arg1 = args[1];
    char *str = malloc(sizeof(char) * (my_strlen(arg1) + 3));
    str = my_strcat(arg1, "=");
    int i = 0;

    while (env[i] != NULL) {
        if (my_strcmp(env[i], arg1) == 0) {
            env[i] = str;
            return 0;
        }
        i++;
    }
    env[i] = str;
    env[i + 1] = NULL;
    return env;
}
