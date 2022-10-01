NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = \
	ft_putfd.c \
	ft_strlen.c \

OBJ = ${SRC:.c=.o}

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJ}
	@ ar rcs ${NAME} ${OBJ}

%.o: %.c libft.h
	@ ${CC} ${CFLAGS} -c -I. $<

clean:
	@ ${RM} ${OBJ}

fclean: clean
	@ ${RM} ${NAME}

re: fclean all