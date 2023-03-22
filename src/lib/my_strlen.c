/*
** MINISHELL2 PROJECT, 2022
** strlen
** File description:
** mystrlen
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
