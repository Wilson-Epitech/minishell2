/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include "struct.h"
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>
    #include <criterion/assert.h>
    #include <criterion/redirect.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdbool.h>

int my_getnbr(char const *str);
char *get_full_path(char *path_value, char *full_path, char **args);
char *get_full_path_loop(char *dir, char *full_path, char **args);
int error_handling_cd(char **args);
void cd_chdir(int nb_args, char *path_home, char **args, char *path_last_lap);
void my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char const *str);
char *my_strncpy(char *dest, char const *src, int size);
int my_strlen(char const *str);
counter_t init_struct(int value);
int check_status(int status);
int my_put_nbr(int nb);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int error_handling(int ac);
int error_handling_getline(char *buffer, size_t size_buffer);
int error_handling_args(char **args);
int end_of_buffer(char *buffer);
int error_handling_fullpath(char *full_path, char **args);
char *my_revstr(char *str);
char *get_path(char **env, char **args);
int exec_command(char *path, char **tmp, char **env);
char *my_strdup(char const *src);
int my_strncmp(char const *str1, char const *str2, int size);
int my_strcmp(char const *str1, char const *str2);
int path_loop(char *existing_path, char **env, char **args);
int exit_command(char **args);
char *check_existing_path(char **args);
int path_loop(char *existing_path, char **env, char **args);
int exit_command(char **args);
int cd_command(char **args, char **env, char const *current_path);
void display_line_shell(char const *current_path, char **env);
char *get_env_line_path(char **env, char *path_value, char *path);
char *get_log_name(char **env);
char **setenv_command(char **args, char **env);

char **malloc_buffer(char **args, char *buffer, size_t size_buffer);

char **shell_command(char **args, char **env,
    char *current_path_save, char **test_env);
char **unsetenv_command(char **args, char **env);
char *handling_path(char *buffer, size_t size_buffer, char **env);
char **setenv_command_one_arg(char **args, char **env);
int check_before_unsetenv(char **args, char **env);
char *get_setenv_line_path(char **env, char *path_value, char *path);
void print_env(char **env);
int check_before_unsetenv(char **args, char **env);
int path_loop(char *existing_path, char **env, char **args);
int bypass_first_lap(int count);
char **clone_env(char **env);
int my_str_isalphanum(char const *str);
int error_setenv_enorme(char **args, char *path_env_empty, char **env);
char *check_env_is_empty(char **env, char **args);
int check_command(char **args, char **env);
int setenv_unsetenv_loop(char **args, char **test_env, char **env);
char **my_str_to_word_array_delim(char const *str, char delim);
#endif /* !LIB_H_ */
