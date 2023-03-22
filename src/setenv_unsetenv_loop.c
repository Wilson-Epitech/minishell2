/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** setenv_unsetenv_loop
*/

#include "../includes/lib.h"

int setenv_unsetenv_loop(char **args, char **test_env, char **env)
{
    if (my_strcmp(args[0], "env") == 0) {
        print_env(test_env);
    }
    if (args[2] != NULL && my_strcmp(args[0], "setenv") == 0) {
        if (my_strcmp(args[0], "setenv") == 0 && args[1] == NULL) {
            return 1;
        }
        setenv_command(args, test_env);
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        unsetenv_command(args, test_env);
    }
    if (args[2] == NULL && my_strcmp(args[0], "setenv") == 0) {
        if (my_strcmp(args[0], "setenv") == 0 && args[1] == NULL) {
            return 1;
        }
        setenv_command_one_arg(args, test_env);
    }
}
