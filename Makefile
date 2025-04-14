NAME = lem-in

SRCS =	src/main.c	\
		parsing/room_input.c \
		parsing/links_input.c \
		parsing/input.c 		\
		execution/bfs.c \
		execution/path.c \
		execution/simulate.c \
		utils/utils.c \
		utils/debug.c

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