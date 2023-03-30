/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** setenv_unsetenv_loop
*/

#include "../includes/lib.h"

static int error_begin_letter(char **args)
{
    if (my_strcmp(args[0], "setenv") == 0 && !is_alphanum_letter(args[1][0])) {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return 1;
    }
    return 0;
}

static int error_setenv_no_arg(char **args)
{
    if (my_strcmp(args[0], "setenv") == 0 && args[1] == NULL) {
            return 1;
    }
    return 0;
}

int setenv_unsetenv_loop(char **args, char **test_env, char **env)
{
    int error = error_setenv_no_arg(args);
    int error_letter = 0;

    print_env(args, test_env);
    if (error == 1)
        return 1;
    if (args[2] != NULL && my_strcmp(args[0], "setenv") == 0) {
        error_letter = error_begin_letter(args);
        if (error_letter == 1)
            return 1;
        setenv_command(args, test_env);
    }
    if (my_strcmp(args[0], "unsetenv") == 0)
        unsetenv_command(args, test_env);
    if (args[2] == NULL && my_strcmp(args[0], "setenv") == 0) {
        error_letter = error_begin_letter(args);
        if (error_letter == 1)
            return 1;
        setenv_command_one_arg(args, test_env);
    }
}
