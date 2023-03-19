##
## MINISHELL2 PROJECT, 2023
## bsminishell
## File description:
## Makefile
##

CC	=	gcc
CCFLAGS	=	-Wextra -Wall -Werror
CFLAGS	=	-g3

SRC	=	src/main.c			\
		src/handling_path.c					\
		src/shell_command.c					\
		src/malloc_buffer.c					\
		src/setenv_command.c					\
		src/exit_command.c					\
		src/cd_command.c					\
		src/error_handling.c				\
		src/display_line_shell.c			\
		src/get_path.c						\
		src/exec.c							\
		src/check_existing_path.c			\
		src/lib/my_putstr.c		\
		src/lib/my_putchar.c		\
		src/lib/my_strlen.c		\
		src/lib/my_str_to_word_array.c	\
		src/lib/my_strcat.c				\
		src/lib/my_strcpy.c				\
		src/lib/my_strncpy.c			\
		src/lib/my_revstr.c				\
		src/lib/my_strdup.c				\
		src/lib/my_strncmp.c			\
		src/lib/my_strcmp.c				\
		src/print_env.c					\
		src/get_setenv_line_path.c		\
		src/check_before_unsetenv.c		\
		src/path_loop.c					\
		src/bypass_first_lap.c			\
		src/clone_env.c					\
		src/lib/my_str_isalphanum.c		\

SRC2	=	src/handling_path.c					\
		src/shell_command.c					\
		src/malloc_buffer.c					\
		src/setenv_command.c					\
		src/exit_command.c					\
		src/cd_command.c					\
		src/error_handling.c				\
		src/display_line_shell.c			\
		src/get_path.c						\
		src/exec.c							\
		src/check_existing_path.c			\
		src/lib/my_putstr.c		\
		src/lib/my_putchar.c		\
		src/lib/my_strlen.c		\
		src/lib/my_put_nbr.c			\
		src/lib/my_str_to_word_array.c	\
		src/lib/my_strcat.c				\
		src/lib/my_strcpy.c				\
		src/lib/my_strncpy.c			\
		src/lib/my_revstr.c				\
		src/lib/my_strdup.c				\
		src/lib/my_strncmp.c			\
		src/lib/my_strcmp.c				\
		src/lib/my_getnbr.c				\
		src/print_env.c					\
		src/get_setenv_line_path.c		\
		src/check_before_unsetenv.c		\
		src/path_loop.c					\
		src/bypass_first_lap.c			\
		src/clone_env.c					\
		src/lib/my_str_isalphanum.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CCFLAGS) $(CFLAGS)

tests_run:
		gcc -o unit_tests $(SRC2) test/unit_test.c --coverage -lcriterion
		./unit_tests

tests_clean:
		$(RM) unit_tests*
		cd unit_test && $(RM) *~

clean	:
	$(RM) $(OBJ)
	$(RM) -f *~
	cd includes && $(RM) -f *~
	cd src && $(RM) -f *~
	cd src/lib && $(RM) -f *~

fclean :	clean
	$(RM) -f $(NAME)

re	:	fclean all
