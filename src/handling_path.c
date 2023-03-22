/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** handling_path
*/

#include "../includes/lib.h"

char *handling_path(char *buffer, size_t size_buffer, char **env)
{
    char *current_path = NULL;
    char *current_path_save = NULL;

    current_path = getcwd(buffer, size_buffer);
    display_line_shell(current_path, env);
    current_path_save = my_strdup(current_path);
    return current_path_save;
}
