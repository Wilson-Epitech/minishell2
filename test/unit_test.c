/*
** MINISHELL2 PROJECT, 2023
** minishell2
** File description:
** unit_test_backup
*/

#include "../includes/lib.h"

Test (exit_command, should_exit) {
    char *args[] = {"exit", NULL};
    cr_assert_eq(exit_command(args), 0);
}

Test (check_existing_path, should_return_existing_path) {
    char *args[] = {"/bin/ls", NULL};
    cr_assert_str_eq(check_existing_path(args), "/bin/ls");
}

Test (check_existing_path, should_return_null) {
    char *args[] = {"ls", NULL};
    cr_assert_null(check_existing_path(args));
}

Test (error_handling, ac_one) {
    int ac = 1;
    cr_assert_eq(error_handling(ac), 0, "Error: ac_one");
}

Test (end_of_buffer, remove_newline) {
    char buffer[10] = "hello\n";
    cr_assert_eq(end_of_buffer(buffer), 0, "Error: remove_newline");
    cr_assert_str_eq(buffer, "hello", "Error: remove_newline");
}

Test (end_of_buffer, no_newline) {
    char buffer[10] = "hello";
    cr_assert_eq(end_of_buffer(buffer), 0, "Error: no_newline");
    cr_assert_str_eq(buffer, "hello", "Error: no_newline");
}

Test (error_handling_args, args_not_null) {
    char *args[2] = {"ls", NULL};
    cr_assert_eq(error_handling_args(args), 0, "Error: args_not_null");
}

Test (error_handling_fullpath, full_path_null) {
    char *args[2] = {"ls", NULL};
    cr_assert_eq(error_handling_fullpath(NULL, args),
        0, "Error: full_path_null");
}

Test (error_handling_fullpath, full_path_not_null) {
    char *args[2] = {"ls", NULL};
    char *full_path = "/bin/ls";
    cr_assert_eq(error_handling_fullpath(full_path, args),
        0, "Error: full_path_not_null");
}

Test (error_handling_fullpath, cd) {
    char *args[2] = {"cd", NULL};
    char *full_path = NULL;
    cr_assert_eq(error_handling_fullpath(full_path, args), 0, "Error: cd");
}

Test (error_handling_fullpath, setenv) {
    char *args[2] = {"setenv", NULL};
    char *full_path = NULL;
    cr_assert_eq(error_handling_fullpath(full_path, args),
        0, "Error: setenv");
}

Test (error_handling_fullpath, unsetenv) {
    char *args[2] = {"unsetenv", NULL};
    char *full_path = NULL;
    cr_assert_eq(error_handling_fullpath(full_path, args),
        0, "Error: unsetenv");
}

Test (bypass_first_lap, count_non_zero) {
    cr_redirect_stdout();
    bypass_first_lap(1);
    cr_assert_stdout_eq_str("\n");
}

Test (bypass_first_lap, count_positive) {
    cr_redirect_stdout();
    bypass_first_lap(5);
    cr_assert_stdout_eq_str("\n");
}

Test (bypass_first_lap, count_negative) {
    cr_redirect_stdout();
    bypass_first_lap(-2);
    cr_assert_stdout_eq_str("\n");
}

Test (display_line_shell, prints_correct_line_shell) {
    char *str = "\033[34m┌──(\033[31muser㉿\033[34m)"
        "-[/home/user]\033[0m\n\033[34m└─$ \033[0m";
    char *current_path = "/home/user";
    char *env[] = {"USER=user", NULL};
    cr_redirect_stdout();
    display_line_shell(current_path, env);
    cr_assert_stdout_eq_str(str);
}

Test (my_strdup, copies_string_correctly) {
    char *src = "Hello, World!";
    char *copy = my_strdup(src);
    cr_assert_str_eq(copy, src);

    free(copy);
}

Test (malloc_buffer, returns_correct_args) {
    char **args = NULL;
    char buffer[] = "ls -la";
    size_t size_buffer = sizeof(buffer);
    args = malloc_buffer(args, buffer, size_buffer);

    cr_assert_str_eq(args[0], "ls");
    cr_assert_str_eq(args[1], "-la");
    cr_assert_null(args[2]);

    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
}

Test (clone_env, basic_test) {
    char *env[] = {"VAR1=value1", "VAR2=value2", NULL};
    char **new_env = clone_env(env);
    cr_assert_str_eq(new_env[0], "VAR1=value1");
    cr_assert_str_eq(new_env[1], "VAR2=value2");
    cr_assert_null(new_env[2]);
    free(new_env[0]);
    free(new_env[1]);
    free(new_env);
}

Test (shell_command, cd_command) {
    char *env[] = {"PWD=/", NULL};
    char *args[] = {"cd", "/", NULL};
    char *current_path_save = "/";
    char **new_env = shell_command(args, env, current_path_save);
    cr_assert_str_eq(new_env[0], "PWD=/");
    cr_assert_null(new_env[1]);
}

Test (shell_command, exit_command) {
    char *env[] = {"VAR1=value1", "VAR2=value2", NULL};
    char *args[] = {"exit", NULL};
    char *current_path_save = "/";
    char **new_env = shell_command(args, env, current_path_save);
    cr_assert_null(new_env);
}

Test (cd_chdir, cd_home_directory) {
    char *path_home = "/home/wilson";
    char *args[] = {"cd", NULL};
    char *path_last_lap = "/home/wilson/B1";
    cd_chdir(1, path_home, args, path_last_lap);
    char *result = getcwd(NULL, 0);
    cr_assert_str_eq(result, path_home);
}

Test (cd_chdir, cd_previous_directory) {
    char *path_home = "/home/wilson";
    char *args[] = {"cd", "-", NULL};
    char *path_last_lap = "/home/wilson/B1";
    cd_chdir(2, path_home, args, path_last_lap);
    char *result = getcwd(NULL, 0);
    cr_assert_str_eq(result, path_last_lap);
}

Test (error_handling_cd, cd_no_arguments) {
    char *args[] = {"cd", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (error_handling_cd, cd_directory_not_found) {
    char *args[] = {"cd", "nonexistent_directory", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (error_handling_cd, cd_file_not_directory) {
    char *args[] = {"cd", "file.txt", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (error_handling_cd, cd_too_many_arguments) {
    char *args[] = {"cd", "directory", "extra_argument", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (check_existing_path, existing_path) {
    char *args[] = {"/bin/ls", "-l", NULL};
    char *result = check_existing_path(args);
    cr_assert_not_null(result);
}

Test (check_existing_path, non_existing_path) {
    char *args[] = {"non_existing_command", NULL};
    char *result = check_existing_path(args);
    cr_assert_null(result);
}

Test (get_path, existing_path) {
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    char *args[] = {"ls", "-l", NULL};
    char *result = get_path(env, args);
    cr_assert_str_eq(result, "/bin/ls");
}

Test (exec_command, ls) {
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    char *args[] = {"ls", "-l", NULL};
    exec_command("/bin/ls", args, env);
    cr_assert(1);
}

Test (, ironment_variables) {
    char *env[] = {"HOME=/home/user", "PATH=/usr/bin:/usr/local/bin", NULL};
    cr_redirect_stdout();
    (env);
    cr_assert_stdout_eq_str("HOME=/home/user\nPATH=/usr/bin:/usr/local/bin\n");
}

Test (get_setenv_line_path, path_found_test) {
    char *env[] = {"PATH=/usr/bin:/usr/local/bin", "VAR=value", NULL};
    char *path = "PATH";
    char *expected_output = "PATH=/usr/bin:/usr/local/bin";
    char *result = NULL;
    result = get_setenv_line_path(env, result, path);
    cr_assert_str_eq(result, expected_output);
    free(result);
}

Test (get_setenv_line_path, path_not_found_test) {
    char *env[] = {"VAR=value", "HOME=/home/user", NULL};
    char *path = "PATH";
    char *expected_output = NULL;
    char *result = NULL;
    result = get_setenv_line_path(env, result, path);
    cr_assert_eq(result, expected_output);
    free(result);
}

// Test(error_handling_getline, valid_input_test) {
//     char buffer[10];
//     size_t size_buffer = 10;
//     char *input = "hello\n";
//     FILE *stream = fmemopen(input, strlen(input), "r");
//     stdin = stream;
//     error_handling_getline(buffer, size_buffer);
//     cr_assert_str_eq(buffer, "hello");
// }

Test (end_of_buffer, buffer_with_newline_test) {
    char buffer[] = "hello\n";
    end_of_buffer(buffer);
    cr_assert_str_eq(buffer, "hello");
}

Test (end_of_buffer, buffer_without_newline_test) {
    char buffer[] = "hello";
    end_of_buffer(buffer);
    cr_assert_str_eq(buffer, "hello");
}

Test (error_handling_fullpath, valid_full_path_test) {
    char *args[] = {"ls", "-l", NULL};
    char *full_path = "/bin/ls";
    cr_assert_eq(error_handling_fullpath(full_path, args), 0);
}

Test (get_env_line_path, basic_test) {
    char *env[] = {"HOME=/home/user",
        "PATH=/usr/local/bin:/usr/bin:/bin", NULL};
    char *path = "PATH=";
    char *path_value = NULL;

    path_value = get_env_line_path(env, path_value, path);
    cr_assert_str_eq(path_value, "/usr/local/bin:/usr/bin:/bin");
}

Test (get_full_path, no_path_value_test) {
    char *path_value = NULL;
    char full_path[100];
    char *args[] = {"ls", NULL};

    char *res = get_full_path(path_value, full_path, args);
    cr_assert_null(res);
}

Test (get_path, no_path_value_test) {
    char *env[] = {"HOME=/home/wilson", NULL};
    char *args[] = {"ls", NULL};

    char *res = get_path(env, args);
    cr_assert_null(res);
}

Test (clone_env, clone_empty_env) {
    char **env = calloc(1, sizeof(char *));
    char **new_env = clone_env(env);

    cr_assert_not_null(new_env);
    cr_assert_eq(new_env[0], NULL);

    free(env);
    free(new_env);
}

Test (clone_env, clone_non_empty_env) {
    char *env[] = {"PATH=/usr/bin", "HOME=/home/user", "USER=user", NULL};
    char **new_env = clone_env(env);

    cr_assert_not_null(new_env);
    cr_assert_str_eq(new_env[0], "PATH=/usr/bin");
    cr_assert_str_eq(new_env[1], "HOME=/home/user");
    cr_assert_str_eq(new_env[2], "USER=user");
    cr_assert_eq(new_env[3], NULL);

    for (int i = 0; i < 3; i++) {
        free(new_env[i]);
    }
    free(new_env);
}

Test (check_before_unsetenv, existing_environment_variable) {
    char *env[] = {"PATH=/usr/bin:/usr/local/bin", "HOME=/home/user", NULL};
    char *args[] = {"unsetenv", "PATH", NULL};
    int result = check_before_unsetenv(args, env);
    cr_assert_eq(result, 0, "Expected return value of 0, but got %d", result);
}

Test (check_before_unsetenv, non_existing_environment_variable) {
    char *env[] = {"HOME=/home/user", NULL};
    char *args[] = {"unsetenv", "PATH", NULL};
    int result = check_before_unsetenv(args, env);
    cr_assert_eq(result, -1, "Expected return value of -1, but got %d", result);
}

Test (check_before_unsetenv, empty_environment) {
    char *env[] = {NULL};
    char *args[] = {"unsetenv", "PATH", NULL};
    int result = check_before_unsetenv(args, env);
    cr_assert_eq(result, -1, "Expected return value of -1, but got %d", result);
}

Test (handling_path, valid_path) {
    char buffer[1024];
    char *env[3] = {"HOME=/home/wilson",
        "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:"
        "/usr/bin:/sbin:/bin:/usr/local/games:/usr/games", NULL};
    char *path = handling_path(buffer, 1024, env);
    cr_assert_not_null(path);
    char cwd[1024];
    cr_assert_str_eq(path, getcwd(cwd, sizeof(cwd)));

    free(path);
}

Test (my_strncpy, copy_empty_string) {
    char dest[10];
    char src[] = "";

    char *result = my_strncpy(dest, src, sizeof(dest));

    cr_assert_str_eq(dest, "");
    cr_assert_eq(result, dest);
}

Test (my_strncpy, copy_string_within_limit) {
    char dest[10];
    char src[] = "hello";

    char *result = my_strncpy(dest, src, sizeof(dest));

    cr_assert_str_eq(dest, "hello");
    cr_assert_eq(result, dest);
}

Test (my_strncpy, copy_string_with_limit) {
    char dest[10];
    char src[] = "helloworld";

    char *result = my_strncpy(dest, src, 5);

    cr_assert_str_eq(dest, "hello");
    cr_assert_eq(result, dest);
}

// Test (my_strncmp, compare_empty_strings) {
//     char str1[] = "";
//     char str2[] = "";

//     int result = my_strncmp(str1, str2, 5);

//     cr_assert_eq(result, 0);
// }

Test (my_strncmp, compare_equal_strings) {
    char str1[] = "hello";
    char str2[] = "hello";

    int result = my_strncmp(str1, str2, strlen(str1));

    cr_assert_eq(result, 0);
}

Test (my_strncmp, compare_different_strings) {
    char str1[] = "hello";
    char str2[] = "world";

    int result = my_strncmp(str1, str2, 5);

    cr_assert(result < 0);
}

Test (my_strlen, calculate_length_of_empty_string) {
    char str[] = "";

    int result = my_strlen(str);

    cr_assert_eq(result, 0);
}

Test (my_strlen, calculate_length_of_non_empty_string) {
    char str[] = "hello world";

    int result = my_strlen(str);

    cr_assert_eq(result, strlen(str));
}

Test (my_strcmp, basic) {
    char const *str1 = "Hello";
    char const *str2 = "Hello";
    int result = my_strcmp(str1, str2);
    cr_assert_eq(result, 0);
}

Test (my_strcmp, different_strings) {
    char const *str1 = "Hello";
    char const *str2 = "World";
    int result = my_strcmp(str1, str2);
    cr_assert_lt(result, 0);
}

Test (my_strcpy, basic) {
    char src[] = "Hello";
    char dest[6];
    my_strcpy(dest, src);
    cr_assert_str_eq(dest, "Hello");
}

Test (my_strdup, basic) {
    char const *src = "Hello";
    char *str = my_strdup(src);
    cr_assert_str_eq(str, "Hello");
    free(str);
}

// Test (my_str_to_word_array, empty_string) {
//     char *str = "";
//     char **result = my_str_to_word_array(str);
//     cr_assert_null(result);
// }

Test (my_str_to_word_array, one_word_string) {
    char *str = "hello";
    char **result = my_str_to_word_array(str);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "hello");
    cr_assert_null(result[1]);
    free(result[0]);
    free(result);
}

Test (my_str_to_word_array, multiple_words_string) {
    char *str = "   hello    world  !  \n";
    char **result = my_str_to_word_array(str);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "hello");
    cr_assert_str_eq(result[1], "world");
    cr_assert_str_eq(result[2], "!");
    cr_assert_null(result[3]);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result);
}

// Test (my_str_to_word_array, only_spaces_string)
// {
//     char *str = "   \t \n ";
//     char **result = my_str_to_word_array(str);
//     cr_assert_null(result);
// }

Test (my_str_to_word_array, mixed_spaces_string) {
    char *str = " hello\tworld  \n!";
    char **result = my_str_to_word_array(str);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "hello");
    cr_assert_str_eq(result[1], "world");
    cr_assert_str_eq(result[2], "!");
    cr_assert_null(result[3]);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result);
}

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test (my_put_nbr, should_print_positive_number, .init = redirect_all_stdout) {
    my_put_nbr(123);
    cr_assert_stdout_eq_str("123");
}

Test (my_put_nbr, should_print_negative_number, .init = redirect_all_stdout) {
    my_put_nbr(-456);
    cr_assert_stdout_eq_str("-456");
}

Test (my_putstr, should_print_string, .init = redirect_all_stdout) {
    my_putstr("Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test (my_revstr, should_reverse_string, .init = redirect_all_stdout) {
    char str[] = "Hello World!";
    char *result = my_revstr(str);
    cr_assert_str_eq(result, "!dlroW olleH");
}

Test (my_strcat, should_concatenate_two_strings, .init = redirect_all_stdout) {
    char str1[] = "Hello ";
    char str2[] = "World!";
    char result[50];
    my_strcat(result, str1);
    my_strcat(result, str2);
    cr_assert_str_eq(result, "Hello World!");
}

Test (my_getnbr, valid_input) {
    cr_assert_eq(my_getnbr("1234"), 1234);
    cr_assert_eq(my_getnbr("42"), 42);
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr("-123"), -123);
    cr_assert_eq(my_getnbr("2147483647"), 2147483647);
    cr_assert_eq(my_getnbr("-2147483648"), -2147483648);
}

Test (my_getnbr, leading_whitespace) {
    cr_assert_eq(my_getnbr("   42"), 42);
    // cr_assert_eq(my_getnbr("\t\t-123"), -123);
}

Test (my_getnbr, trailing_whitespace) {
    cr_assert_eq(my_getnbr("42  "), 42);
    // cr_assert_eq(my_getnbr("-123\t\t"), -123);
}
