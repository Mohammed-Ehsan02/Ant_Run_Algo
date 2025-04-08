NAME = lemin

SRCS =	main.c	\
		utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror

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