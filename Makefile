##
## EPITECH PROJECT, 2024
## makefile
## File description:
## make
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Iinclude -g3

NAME	=	setting_up

SRC	=	src/main.c\
		src/find_square.c\
		src/board.c\
		src/my.c\
		src/my2.c\
		src/utils.c\
		src/utils2.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
