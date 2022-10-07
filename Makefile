NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

INC = -Iincludes -Ilibft/includes
LIB = -L. -lft -lmlx -lX11 -lXext -lm

.PHONY: all clean fclean re

all: ${NAME}

SRC_NAMES = \
	cub3d.c \
	destroy.c \
	error.c \
	get_next_line.c \
	main.c \
	parser.c \
	print_utils.c \
	math_lib/add_points.c \
	math_lib/copy.c \
	math_lib/create.c \
	math_lib/dist.c \
	math_lib/inner_product.c \
	math_lib/neg.c \
	math_lib/normalize.c \
	math_lib/norm.c \
	math_lib/rot.c \
	math_lib/scalar_mul.c \
	math_lib/sub.c \

SRC = $(addprefix src/, ${SRC_NAMES})
OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ} libft/libft.a minilibx-linux/libmlx.a
	${CC} ${CFLAGS} -o $@ ${OBJ} ${LIB}

%.o: %.c includes/cub3d.h includes/math_lib.h
	${CC} ${CFLAGS} -c -o ${<:.c=.o} $< ${INC}

libft/libft.a:
	make -C libft
	cp libft/libft.a .

minilibx-linux/libmlx.a:
	make -C minilibx-linux
	cp minilibx-linux/libmlx.a .

clean:
	${RM} ${OBJ}
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	${RM} ${NAME} libft.a libmlx.a minilibx-linux/libmlx.a
	make -C libft fclean

re: fclean all