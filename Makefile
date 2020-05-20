##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/handle_arg.c	\
		src/def_firsts_funct.c	\
		src/def_lasts_funct.c	\
		src/create_map.c	\
		src/read_forms.c	\
		src/read_form_shape.c	\
		src/debug_mode.c	\
		src/debug_mode_tetri.c	\
		src/game_loop.c	\
		src/game_render.c	\
		src/game_render_interface.c	\
		src/game_event.c	\
		src/game_event_move.c	\
		src/game_event_rotate_piece.c	\
		src/game_event_move_check.c	\
		src/game_handling_piece.c	\
		src/place_piece.c	\
		src/delete_full_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS += -I ./include/

CFLAGS += -l ncurses -L ./lib/ -lmy

all:   $(NAME)

$(NAME):    $(OBJ)
	make -C lib/my/
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
