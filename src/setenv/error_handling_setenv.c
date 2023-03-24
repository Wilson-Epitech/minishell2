/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** error_handling_setenv
*/

#include "../../includes/lib.h"

char *check_env_is_empty(char **env, char **args)
{
    char *path = "PATH=";
    char *path_return = NULL;
    path_return = get_env_line_path(env, path_return, path);
    return path_return;
}

static char *error_message_setenv(char **env, char **args)
{
    char *path = "setenv";
    if (my_strcmp(args[0], path) == 0 && args[1][1] <= 9 && args [1][1] >= 0) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    return 0;
}

static int check_isnum(char **args)
{
    char *var_name = args[1];
    if (my_strcmp(args[0], "setenv") == 0 && !my_str_isalphanum(var_name)) {
        my_putstr(
            "setenv: Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

int error_setenv_enorme(char **args, char *path_env_empty, char **env)
{
    int error = 0;
    if (my_strncmp(args[0], "setenv", 5) == 0 && args[1] == NULL) {
        return 1;
    }
    if (path_env_empty == NULL
        && my_strcmp(args[0], "setenv") == 0) {
            return 1;
    } else {
        error_message_setenv(env, args);
    }
    error = check_isnum(args);
    if (error == 1) {
        return 1;
    }
}
