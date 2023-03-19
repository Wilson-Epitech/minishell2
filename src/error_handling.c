/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** error_handling
*/

#include "../includes/lib.h"

int error_handling(int ac)
{
    if (ac != 1) {
        exit(84);
    }
    return 0;
}

int error_handling_getline(char *buffer, size_t size_buffer)
{
    end_of_buffer(buffer);
    if (getline(&buffer, &size_buffer, stdin) == -1) {
        exit(0);
    }
    return 0;
}

int end_of_buffer(char *buffer)
{
    int len = my_strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    return 0;
}

int error_handling_args(char **args)
{
    if (args == NULL) {
        exit(84);
    }
    return 0;
}

int error_handling_fullpath(char *full_path, char **args)
{
    char *cd = "cd";
    char *setenv = "setenv";
    char *unsetenv = "unsetenv";
    if (full_path == NULL && (!my_strcmp(cd, args[0]) == 0)
        && (!my_strcmp(setenv, args[0]) == 0)
        && (!my_strcmp(unsetenv, args[0]) == 0)) {
        my_putstr(args[0]);
        my_putstr(": Command not found.");
        my_putchar('\n');
    }
    return 0;
}
