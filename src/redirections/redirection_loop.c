/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** redirection_loop
*/

#include "../../includes/lib.h"

char **execute_redirection_loop(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strncmp(args[i], ">", 1) == 0 && args[i][1] == '\0') {
            simple_right_redirection(args, i);
            args[i] = NULL;
            return args;
        }
        if (my_strncmp(args[i], "<", 1) == 0 && args[i][1] == '\0') {
            simple_left_redirection(args, i);
            return args;
        }
        if (my_strncmp(args[i], ">>", 2) == 0) {
                double_right_redirection(args, i);
                args[i] = NULL;
                return args;
        }
        if (my_strncmp(args[i], "<<", 2) == 0) {
                double_left_redirection(args, i);
                return args;
        }
    } return args;
}
