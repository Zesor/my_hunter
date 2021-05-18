##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	amazing.c	\
		description.c

OBJ	=	$(SRC:.o=.c)

CFLAGS	=	-Wall -Wextra

NAME	=	my_hunter

CPPFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS)

clean:
		@rm -f *.o
		@rm -f $(NAME)

fclean: clean

re: clean fclean