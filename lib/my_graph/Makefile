##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## create the lib
##

SRC    =	create_window.c	\
			move_sprite_by_translation.c	\
			move_sprite_by_rotation.c	\
			get_seconds.c	\
			displays_sprite.c	\
			destroy_sprite.c	\

OBJ    =    $(SRC:.c=.o)

NAME   =    my_graph

all:   $(NAME)

$(NAME):	$(OBJ)
		ar rc lib$(NAME).a $(OBJ)
		cp lib$(NAME).a ..
		cp my_graph.h ../../include

clean:
	  rm $(OBJ)

fclean: clean

re:    all fclean
