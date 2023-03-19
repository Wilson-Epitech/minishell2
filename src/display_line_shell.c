/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** display_line_shell
*/

#include "../includes/lib.h"

void display_line_shell(char const *current_path, char **env)
{
    char *usr_path = "USER=";
    char *log_name = get_env_line_path(env, log_name, usr_path);
    my_putstr("\033[34m┌──(\033[31m");
    my_putstr(log_name);
    my_putstr("㉿\033[34m)-[");
    my_putstr(current_path);
    my_putstr("]\033[0m");
    my_putchar('\n');
    my_putstr("\033[34m└─$ \033[0m");
}
