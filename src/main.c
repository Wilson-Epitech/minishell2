/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** main
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

int main(int ac, char **av, char **env)
{
    size_t size_buffer = 100;
    char *buffer = malloc(sizeof(char) * (size_buffer));
    int count = 0;

    error_handling(ac);
    while (1) {
        bypass_first_lap(count);
        char *current_path_save = handling_path(buffer, size_buffer, env);
        error_handling_getline(buffer, size_buffer);
        char **args = malloc_buffer(args, buffer, size_buffer);
        int state = check_command(args, env);
        if (args == NULL || args[0] == NULL || state == 1) {
            free(args);
            continue;
        }
        shell_command(args, env, current_path_save);
        free(args); count ++;
    }
    free(buffer);
    return 0;
}
