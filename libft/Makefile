NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	free_array.c \
	free_str_list.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_endswith.c \
	ft_is_in_charlist.c \
	ft_isblank.c \
	ft_isdigit.c \
	ft_isspace.c \
	ft_max_int.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putstr_fd.c \
	ft_startswith.c \
	ft_strcat.c \
	ft_strip.c \
	ft_strlen.c \
	ft_strndup.c \
	lst_add_n.c \
	lst_add.c \

OBJ = ${SRC:.c=.o}

INC = -Iincludes

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJ}
	@ ar rcs ${NAME} ${OBJ}

%.o: %.c includes/libft.h
	${CC} ${CFLAGS} -c $< -Iincludes

clean:
	@ ${RM} ${OBJ}

fclean: clean
	@ ${RM} ${NAME}

re: fclean all