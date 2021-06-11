##
## EPITECH PROJECT, 2021
## B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
## File description:
## Makefile
##

SRC	= 	is_prime_number.c \
		my_putchar.c \
		my_puterror.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strncmp.c \
		my_strstr.c \
		my_strcmp.c \
		reverse_string.c \
		show_number.c \
		show_string.c \
		is_alphanum.c \
		show_params.c \
		show_error.c \
		my_swap.c \
		my_strcat.c \
		my_str_to_word_array.c \
		my_to_number.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) -g
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	@make clean
	@rm -f $(NAME)

re: fclean all
