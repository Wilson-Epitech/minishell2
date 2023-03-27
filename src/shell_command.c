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
