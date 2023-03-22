/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** malloc_buffer
*/

#include "../includes/lib.h"

char **malloc_buffer(char **args, char *buffer, size_t size_buffer)
{
    args = malloc(sizeof(char*) * size_buffer);
    error_handling_args(args);
    args = my_str_to_word_array(buffer);
    return args;
}
