/*
** MINISHELL2 PROJECT, 2022
** my_putchar
** File description:
** func
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
