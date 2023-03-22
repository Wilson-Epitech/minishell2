/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** get_path
*/

#include "../includes/lib.h"

char *get_env_line_path(char **env, char *path_value, char *path)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(path, env[i], my_strlen(path)) == 0) {
            path_value = my_strdup(env[i] + my_strlen(path));
            break;
        }
    }
    return path_value;
}

char *get_full_path_loop(char *dir, char *full_path, char **args)
{
    while (dir != NULL) {
            my_strcpy(full_path, dir);
            my_strcat(full_path, "/");
            my_strcat(full_path, args[0]);
            if (access(full_path, X_OK) == 0) {
                return full_path;
            }
            dir = strtok(NULL, ":");
    }
}

char *get_full_path(char *path_value, char *full_path, char **args)
{
    if (path_value != NULL) {
        char *dir = strtok(path_value, ":");
        size_t path_len = my_strlen(dir);
        size_t arg_len = my_strlen(args[0]);
        full_path = malloc(sizeof(char) * (path_len + 1 + arg_len + 1));
        if (get_full_path_loop(dir, full_path, args) != NULL) {
            return full_path;
        }
    }
    return NULL;
}

char *get_path(char **env, char **args)
{
    char *path = "PATH=";
    char *path_value = NULL;
    char *full_path ;

    path_value = get_env_line_path(env, path_value, path);
    full_path = get_full_path(path_value, full_path, args);
    error_handling_fullpath(full_path, args);
    return full_path;
}
