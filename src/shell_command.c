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
    int output_file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (output_file == -1) {
        return -1;
    }

    dup2(output_file, STDOUT_FILENO);
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

char **execute_redirection_loop(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strncmp(args[i], ">", 1) == 0) {
            simple_right_redirection(args, i);
            args[i] = NULL;
            return args;
        }
        if (my_strncmp(args[i], "<", 1) == 0) {
            simple_left_redirection(args);
        }
    }
    return args;
}

char **shell_command(char **args, char **env,
    char *current_path_save, char **test_env)
{
    char *path_env_empty = check_env_is_empty(env, args);
    char *existing_path = NULL;
    char **new_env = clone_env(env);
    int fd_backup = dup(1);
    exit_command(args);
    setenv_unsetenv_loop(args, test_env, env);
    cd_command(args, env, current_path_save);
    args = execute_redirection_loop(args);
    execute_pipe(args);
    existing_path = check_existing_path(args);
    path_loop(existing_path, env, args);
    dup2(fd_backup, STDOUT_FILENO);
    return env;
}
