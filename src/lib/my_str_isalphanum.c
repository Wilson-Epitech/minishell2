/*
** MINISHELL2 PROJECT, 2023
** cpool
** File description:
** my_str_isnum
*/

int my_isalnum(char c)
{
    if ((c >= '0' && c <= '9')
        || (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

int my_str_isalphanum(char const *str)
{
    int i = 0;
    while (str[i]) {
        if (!my_isalnum(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}
