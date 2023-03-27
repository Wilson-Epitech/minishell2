/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** is_word_separator
*/

#include "../../includes/lib.h"

bool is_word_separator(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}
