# NAME = lem-in
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3
# INCLUDES = -Iincludes -Ilibft

# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a

# OBJ_DIR = obj

# SRC = \
# 	src/main.c \
# 	parsing/room_input.c \
# 	parsing/links_input.c \
# 	parsing/input.c 		\
# 	execution/bfs.c \
# 	execution/path.c \
# 	execution/simulate.c \
# 	utils/utils.c \
# 	utils/debug.c

# # Map .c → obj/.o
# OBJ = $(SRC:.c=.o)
# OBJ := $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJ))

# # Auto-create obj subdirectories
# DIRS = $(sort $(dir $(OBJ)))

# all: $(NAME)

# $(NAME): $(OBJ) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

# # Compile .c to obj/.o and create folders as needed
# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# $(LIBFT):
# 	make -C $(LIBFT_DIR)
# 	make bonus -C $(LIBFT_DIR)

# clean:
# 	rm -rf $(OBJ_DIR)
# 	make fclean -C $(LIBFT_DIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

NAME = lem-in

SRCS =	src/main.c	\
		parsing/room_input.c \
		parsing/links_input.c \
		parsing/input.c 		\
		execution/bfs.c \
		execution/path.c \
		execution/simulate.c \
		utils/utils.c \
		utils/debug.c \
		utils/clean_up.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror #-fsanitize=address

all : $(NAME)

$(NAME): $(OBJS)
	make -C ./libft && make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L ./libft -lft

clean:
	cd libft && make fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
