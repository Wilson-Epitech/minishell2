/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** check_command
*/

#include "../includes/lib.h"

int check_command(char **args, char **env)
{
    char *path = "PATH=";
    char *path_value = get_env_line_path(env, path_value, path);
    if (path_value == NULL) {
        my_putstr(args[0]);
        my_putstr(": Command not found.\n\n");
        return 1;
    } else if (*path_value == '\0') {
        my_putstr(args[0]);
        my_putstr(": Command not found.\n\n");
        return 1;
    }
    return 0;
}
