##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles the libmy
##

NAME 	=	my_sokoban

SRC		=	src/main.c			\
			src/my_putthings.c	\
			src/map.c			\
			src/sokoban.c		\
			src/game.c\
			src/movements/player_movement.c\
			
OBJ		=	$(SRC:%.c=%.o)

CC		=	gcc

CFLAGS	=	-g -c -W -Wall -Wshadow -I./includes/

LDFLAGS	=	-lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re