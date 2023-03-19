/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** clone_env
*/

#include "../includes/lib.h"

char **clone_env(char **env)
{
    int i = 0;
    while (env[i] != NULL) {
        i++;
    }
    char **new_env = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++) {
        new_env[j] = my_strdup(env[j]);
    }
    new_env[i] = NULL;
    return new_env;
}
