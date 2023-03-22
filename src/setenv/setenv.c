/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** setenv
*/

#include "../../includes/lib.h"



char **setenv_command(char **args, char **env)
{
    char *arg1 = args[1]; char *arg2 = args[2];
    char *str = malloc(sizeof(char) * (my_strlen(arg1) + my_strlen(arg2) + 2));
    str = my_strcat(arg1, "="); str = my_strcat(str, arg2);
    int i = 0;

    while (env[i] != NULL) {
        if (my_strcmp(env[i], arg1) != 0) {
            env[i] = str;
            return 0;
        }
        i++;
    }
    env[i] = str;
    env[i + 1] = NULL;
    return env;
}
