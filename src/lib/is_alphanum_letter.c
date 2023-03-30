/*
** MINISHELL2 PROJECT, 2023
** mouli_63%_avant_modif_setenv_C1
** File description:
** is_alphanum_letter
*/

#include "../../includes/lib.h"

bool is_alphanum_letter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}
