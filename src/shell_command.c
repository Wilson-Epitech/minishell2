/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** shell_command
*/

#include "../includes/lib.h"

static int execute_pipe(char **args)
{
    int pipe = 0;
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strncmp(args[i], "|", 1) == 0) {
            pipe = 1;
        }
    }
    return 0;
}

static int simple_right_redirection(char **args, int i)
{
    char *filename = args[i + 1];
    int output_file = 0;

    if (filename != NULL && access(filename, F_OK) != -1) {
        output_file = open(filename, O_WRONLY | O_TRUNC);
    } else {
        output_file = open(filename, O_WRONLY | O_CREAT, 0644);
    }
    if (output_file < 0) {
        return -1;
    }
    if (dup2(output_file, STDOUT_FILENO) < 0) {
        close(output_file);
        return -1;
    }
    close(output_file);
    return 0;
}

static int simple_left_redirection(char **args)
{
    return 0;
}

int execute_redirection_loop(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strncmp(args[i], ">", 1) == 0) {
            simple_right_redirection(args, i);
        }
        if (my_strncmp(args[i], "<", 1) == 0) {
            simple_left_redirection(args);
        }
    }
    return 0;
}

char **shell_command(char **args, char **env,
    char *current_path_save, char **test_env)
{
    char *path_env_empty = check_env_is_empty(env, args);
    char *existing_path = NULL;
    char **new_env = clone_env(env);
    exit_command(args);
    setenv_unsetenv_loop(args, test_env, env);
    cd_command(args, env, current_path_save);
    execute_pipe(args);
    existing_path = check_existing_path(args);
    path_loop(existing_path, env, args);
    return env;
}
