/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** unsetenv
*/

#include "../../includes/lib.h"

#include <stddef.h>

static void swap_str(char **str1, char **str2)
{
    char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
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
            while (env[j + 1] != NULL) {
                swap_str(&env[j], &env[j + 1]);
                j++;
            }
            env[j] = NULL;
            return env;
        }
        i++;
    }
    return env;
}

char **unsetenv_command(char **args, char **env)
{
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
