NAME = parsing_check
NAME_LIBFT = libft.a

NORMINETTE_BIN = norminette
NM_BIN = nm

SRCS =  main.c \
		parsing/data_sanity.c \
		parsing/name_sanity.c \
		parsing/run_parser.c \
		parsing/buffer_file.c \
		parsing/parse_textures.c \
		parsing/parse_rgb.c \
		parsing/check_textures.c \
		debug/print_game_struct.c \
		debug/print_color_struct.c \
		memory/destroy_game.c \
		linter/print_errors.c \

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
	@ ${NORMINETTE_BIN} ${SRCS} includes

sym:
	${NM_BIN} -n $(OBJS)

test: all
	@ python3 tests.py

test_all: all
	@ python3 tests.py -a

test_leaks: all
	@ python3 tests.py -l

test_errors:
	@ python3 tests.py -e

.PHONY: all clean fclean re norme sym test test_all test_leaks test_errors
