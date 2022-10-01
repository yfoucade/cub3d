NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIB = -lft -lmlx -lX11 -lXext

.PHONY: all clean fclean re

all: ${NAME}

OBJ_NAMES = main.o

OBJ = $(addprefix src/, ${OBJ_NAMES})

${NAME}: ${OBJ} #libft/libft.a minilibx-linux/libmlx.a
	${CC} ${CFLAGS} -o $@ ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c -o ${<:.c=.o} $^ -I include

libft/libft.a:
	make -C libft

minilibx-linux/libmlx.a:
	make -C minilibx-linux

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all