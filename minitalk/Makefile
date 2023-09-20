NAME = server client
SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: server client

server: server.o
	make -C libft
	$(CC) -o $@ $< $(LIBFT)

client: client.o
	make -s -C libft
	$(CC) -o $@ $< $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re