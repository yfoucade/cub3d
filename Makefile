NAME = parsing_check
NAME_LIBFT = libft.a

NORMINETTE_BIN = norminette
NM_BIN = nm

SRCS =  main.c \
		parsing/load/buffer_file.c \
		parsing/load/buffer_map.c \
		parsing/parse_rgb.c \
		parsing/parse_settings.c \
		parsing/run_parser.c \
		parsing/sanity/check_settings.c \
		parsing/sanity/data_sanity.c \
		parsing/sanity/name_sanity.c \
		parsing/sanity/map_sanity.c \
		parsing/map_to_matrix.c \
		debug/print_game_struct.c \
		debug/print_color_struct.c \
		debug/print_matrix.c \
		memory/destroy_game.c \
		linter/color_errors.c \
		linter/io_errors.c \
		linter/print_errors.c \
		linter/settings_errors.c \
		linter/textures_errors.c \
		linter/map_errors.c \

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
