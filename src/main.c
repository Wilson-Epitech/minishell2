/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** main
*/

#include "../includes/lib.h"

static char **define_env(char **env)
{
    char **test_env = NULL;
    if (env[0] == NULL) {
        test_env = malloc(sizeof(char *));
        test_env[0] = NULL;
    } else {
        test_env = env;
    }
    return test_env;
}

int main(int ac, char **av, char **env)
{
    size_t size_buffer = 100;
    char *buffer = malloc(sizeof(char) * (size_buffer));
    int count = 0;
    char **test_env = define_env(env);
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
        shell_command(args, env, current_path_save, test_env);
        free(args); count ++;
    }
    free(buffer);
    return 0;
}
