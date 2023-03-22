/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int size)
{
    int i = 0;

    while (i < size && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
