##
## EPITECH PROJECT, 2021
## B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
## File description:
## Makefile
##

SRC	= 	./src/main.c \
		./src/env.c \
		./src/env2.c \
		./src/parsing.c \
		./src/execute.c \
		./src/my_shell.c \
		./src/clean.c \
		./src/my_cd.c \
		./src/check.c \
		./src/pipe.c \
		./src/pid.c \
		./src/free.c

NAME = mysh

OBJ		=	$(SRC:.c=.o)

CFLAGS 	=	-I include -g

LIB_LOCATION = ./lib/my

LIB = -L $(LIB_LOCATION) -l my

all	: $(NAME)

$(NAME)	:	$(OBJ)
	make -C $(LIB_LOCATION)
	gcc -Wall -Wextra -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean	:
	rm -f $(OBJ)
	make clean -C $(LIB_LOCATION)

fclean	:	clean
	rm -f $(NAME)
	make fclean -C $(LIB_LOCATION)

re	: fclean all
