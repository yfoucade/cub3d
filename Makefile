NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIB = -lft -lmlx -lX11 -lXext

.PHONY: all clean fclean re

all: ${NAME}

OBJ_NAMES = \
	error.o \
	main.o \
	math_lib/add_points.o \

OBJ = $(addprefix src/, ${OBJ_NAMES})

${NAME}: ${OBJ} libft/libft.a #minilibx-linux/libmlx.a
	${CC} ${CFLAGS} -o $@ ${OBJ} -lft -L.

%.o: %.c
	${CC} ${CFLAGS} -c -o ${<:.c=.o} $^ -Iinclude -Ilibft

libft/libft.a:
	make -C libft
	cp libft/libft.a .

minilibx-linux/libmlx.a:
	make -C minilibx-linux

clean:
	${RM} ${OBJ}
	make -C libft clean

fclean: clean
	${RM} ${NAME}
	make -C libft fclean

re: fclean all