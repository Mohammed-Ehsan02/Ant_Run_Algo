NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

SRC = \
	src/main.c \
	# parsing/input.c \
	# parsing/room_parser.c \
	# parsing/link_parser.c \
	# parsing/hash_utils.c \
	# execution/graph.c \
	# execution/paths.c \
	# execution/simulate.c \
	# execution/output.c \
	# utils/str_utils.c \
	# utils/error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
