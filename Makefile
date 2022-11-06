NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

INC = -Iincludes -Ilibft/includes
LIB = -L. -lft -lmlx -lX11 -lXext -lm

.PHONY: all clean fclean re

SRC = \
	src/cub3d.c \
	src/destroy.c \
	src/error.c \
	src/game/draw.c \
	src/game/init.c \
	src/game/loop.c \
	src/game/raycasting/bounds.c \
	src/game/raycasting/dda.c \
	src/game/raycasting/distance.c \
	src/game/raycasting/vars.c \
	src/game/raycasting/wall_collision.c \
	src/game/render.c \
	src/game/run.c \
	src/get_next_line.c \
	src/hooks/exit.c \
	src/hooks/init.c \
	src/hooks/key.c \
	src/main.c \
	src/math_lib/abs.c \
	src/math_lib/add_points.c \
	src/math_lib/copy.c \
	src/math_lib/create.c \
	src/math_lib/dist.c \
	src/math_lib/get_perp.c \
	src/math_lib/inner_product.c \
	src/math_lib/neg.c \
	src/math_lib/normalize.c \
	src/math_lib/norm.c \
	src/math_lib/rot.c \
	src/math_lib/scalar_mul.c \
	src/math_lib/sub.c \
	src/parsing/map_data.c \
	src/parsing/parse.c \
	src/parsing/parse_color.c \
	src/parsing/parse_line.c \
	src/parsing/read_file.c \
	src/parsing/sanity.c \
	src/parsing/transform.c \
	src/parsing/types.c \
	src/parsing/utils/ft_count_words.c \
	src/parsing/utils/ft_parse_rgb.c \
	src/parsing/utils/ft_set_color.c \
	src/parsing/utils/ft_split.c \
	src/parsing/utils/init.c \
	src/position/collisions.c \
	src/position/update.c \
	src/print_utils.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} libft/libft.a minilibx-linux/libmlx.a
	@ echo ${OBJ}
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