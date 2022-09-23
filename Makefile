NAME = parsing_check
NAME_LIBFT = libft.a

NORMINETTE_BIN = norminette
NM_BIN = nm

SRCS =  main.c \
		parsing/data_sanity.c \
		parsing/name_sanity.c \
		linter/push_error.c \

OBJS := ${SRCS:.c=.o}

CC = cc

RM = rm -f

INCLUDE_DIR = -I includes -I libft/includes

CFLAGS = -Wall -Wextra -Werror -g3

.c.o:
	${CC} ${CFLAGS} -c ${INCLUDE_DIR} $< -o ${<:.c=.o}

all: $(NAME_LIBFT) $(NAME)

$(NAME): ${OBJS}
	$(CC) $(CFLAGS) ${INCLUDE_DIR} -o $(NAME) ${OBJS} $(NAME_LIBFT)

$(NAME_LIBFT):
	${RM} $(NAME_LIBFT)
	make -C libft/
	cp libft/libft.a $(NAME_LIBFT)

clean:
	make -C libft/ clean
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME_LIBFT) $(NAME)

re: fclean all

norme:
	@${NORMINETTE_BIN} ${SRCS} includes/so_long.h
	make -C libft/ norme

sym:
	${NM_BIN} -n $(OBJS)

.PHONY: all clean fclean re norme sym
