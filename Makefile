.PHONY: clean, fclean, re, all

.SUFFIXES:

NAME = fdf

SRC 	= fdf.c \
		testmlx.c \

OBJ = *.o

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
LIBINC = -I ./libft
LIBLINK = -L ./libft -lft

all: $(NAME)

$(NAME) :
	make -C ../../../Lib_ft
	gcc -g $(CFLAGS) fdf.h main.c mlx.c calculs.c draw.c hook.c parsing.c check.c ../../gnl/get_next_line.c ../../gnl/get_next_line.h ../../../Lib_ft/libft.a ../../../minilibx_macos/libmlx.a -framework AppKit -framework OpenGl

clean:
	make -C ../../../Lib_ft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ../../../Lib_ft fclean
	rm -f $(NAME)

re: fclean all
