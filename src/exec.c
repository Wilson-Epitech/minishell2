/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** exec
*/

#include "../includes/lib.h"

int exec_command(char *path, char **tmp, char **env)
{
    pid_t pid = fork();
    if (pid == -1) {
        exit(84);
    }
    if (pid == 0) {
        execve(path, tmp, env);
        exit(84);
    } else {
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            exit(84);
        }
    }
    return 0;
}
