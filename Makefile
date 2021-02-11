##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	my_hunter

SRC	=	src/main.c	\
		src/events.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/

LDLIBS	=	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS) -lm -l csfml-window -l csfml-graphics -l csfml-system

make_lib:
		$(MAKE) -C lib/my

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my

re:		fclean all
		$(MAKE) re -C lib/my
