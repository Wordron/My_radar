##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC		=	my_radar.c	\
			analyse_event.c	\
			get_info_aircraft.c	\
			get_info_tower.c	\
			get_info_from_file.c	\
			create_object.c	\
			create_aircraft.c	\
			create_circle.c	\
			create_square.c	\
			destroy.c	\
			start_display_sprites.c	\
			display.c	\
			move_aircraft.c	\
			check_colisions.c	\

OBJ    =    $(SRC:.c=.o)

NAME	=	my_radar

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my_graph
		make -C lib/my
		gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system \
		-l csfml-window -Llib -lmy_graph -Llib -lmy -lm

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
