/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** malloc_buffer
*/

#include "../includes/lib.h"

char **malloc_buffer(char **tab, char *args, size_t size_buffer)
{
    tab = malloc(sizeof(char*) * size_buffer);
    error_handling_args(tab);
    tab = my_str_to_word_array(args);
    return tab;
}
