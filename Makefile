NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -Iincludes -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ_DIR = obj

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

# Map .c → obj/.o
OBJ = $(SRC:.c=.o)
OBJ := $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJ))

# Auto-create obj subdirectories
DIRS = $(sort $(dir $(OBJ)))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

# Compile .c to obj/.o and create folders as needed
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
