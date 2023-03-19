/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** check_before_unsetenv
*/

#include "../includes/lib.h"

int check_before_unsetenv(char **args, char **env)
{
    size_t len = my_strlen(args[1]);
    char *path = malloc(sizeof(char) * (len + 2));
    path = my_strcat(path, args[1]);
    path = my_strcat(path, "=");

    char *path_value = get_env_line_path(env, NULL, path);
    if (path_value == NULL) {
        free(path);
        return -1;
    }
    free(path);
    return 0;
}
