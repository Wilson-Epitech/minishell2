/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** check_existing_path
*/

#include "../includes/lib.h"

char *check_existing_path(char **args)
{
    char *existing_path;
    for (int i = 0; args[0][i] != '\0'; i++) {
        if (args[0][i] == '/' && access(args[0], X_OK) == 0) {
            return args[0];
        }
        if (args[0][i] == '/' && access(args[0], X_OK) == -1) {
            return NULL;
        }
    }
    return NULL;
}
