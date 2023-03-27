/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** simple_right_redirection
*/

#include "../../includes/lib.h"

int simple_right_redirection(char **args, int i)
{
    char *filename = args[i + 1];
    int output_file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (output_file == -1) {
        return -1;
    }

    dup2(output_file, STDOUT_FILENO);
        if (dup2(output_file, STDOUT_FILENO) < 0) {
            close(output_file);
        return -1;
    }
    close(output_file);
    return 0;
}
