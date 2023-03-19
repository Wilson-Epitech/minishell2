/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** path_loop
*/

#include "../includes/lib.h"

int path_loop(char *existing_path, char **env, char **args)
{
    if (existing_path == NULL) {
        char *full_path = get_path(env, args);
        int status = exec_command(full_path, args, env);
    } else {
        int status = exec_command(existing_path, args, env);
    }
}
