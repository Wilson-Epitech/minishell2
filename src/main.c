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

static void main_loop(char *buffer, size_t size_buffer,
    char **env, char **test_env)
{
    int count = 0;
    bypass_first_lap(count);
    char *current_path_save = handling_path(buffer, size_buffer, env);
    error_handling_getline(buffer, size_buffer);
    char **args = my_str_to_word_array_delim(buffer, ';');
    for (int x = 0; args[x] != NULL; x++) {
        char **tab = malloc_buffer(tab, args[x], size_buffer);
        int state = check_command(tab, env);
            if (tab == NULL || args[0] == NULL || state == 1) {
                free(args[x]);
                continue;
            }
    shell_command(tab, env, current_path_save, test_env);
    free(tab);
    count ++;
    }
}

int main(int ac, char **av, char **env)
{
    size_t size_buffer = 100;
    char *buffer = malloc(sizeof(char) * (size_buffer));
    int x = 0;
    char **test_env = define_env(env);
    error_handling(ac);
    while (1) {
        main_loop(buffer, size_buffer, env, test_env);
    }
    free(buffer);
    return 0;
}
