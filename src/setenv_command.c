/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** setenv_command
*/

#include "../includes/lib.h"

extern char **environ;

int error_handling_setenv_unsetenv(char **args, char **env)
{
    if (args[2] != NULL && args[1] == NULL
        && my_strcmp(args[0], "setenv") == 0) {
        print_env(env);
    }
    if (args[1] == NULL && my_strcmp(args[0], "unsetenv") == 0) {
        my_putstr("Unsetenv : Too few arguments");
        return 0;
    }
    return 0;
}

char **setenv_command_one_arg(char **args, char **env)
{
    env = environ;
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

char **setenv_command(char **args, char **env)
{
    error_handling_setenv_unsetenv(args, env);
    env = environ;
    char *arg1 = args[1]; char *arg2 = args[2];
    char *str = malloc(sizeof(char) * (my_strlen(arg1) + my_strlen(arg2) + 2));
    str = my_strcat(arg1, "="); str = my_strcat(str, arg2);
    int i = 0;

    if (my_strcmp(arg1, "env") == 0) {
        print_env(environ);
    }
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

char **unsetenv_command_loop(char **args, char **env)
{
    char *arg1 = args[1];
        char *path = my_strcat(arg1, "=");
        char *path_value = NULL;
        path_value = get_setenv_line_path(env, path_value, path);

        int i = 0;
        while (env[i] != NULL) {
            if (my_strcmp(env[i], path_value) == 0) {
                int j = i;
                while (env[j] != NULL) {
                    env[j] = NULL;
                    j++;
                }
                env[j - 1] = NULL;
                return env;
            }
            i++;
        }
    return env;
}

char **unsetenv_command(char **args, char **env)
{
    env = environ;
    if (args[1] == NULL && my_strcmp(args[0], "unsetenv") == 0) {
        my_putstr("Unsetenv : Too few arguments\n");
        return 0;
    }
    int state = check_before_unsetenv(args, env);
    if (state != -1) {
        unsetenv_command_loop(args, env);
    }
    return 0;
}
