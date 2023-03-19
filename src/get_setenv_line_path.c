/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** get_setenv_line_path
*/

#include "../includes/lib.h"

char *get_setenv_line_path(char **env, char *path_value, char *path)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(path, env[i], my_strlen(path)) == 0) {
            path_value = my_strdup(env[i]);
            break;
        }
    }
    return path_value;
}
