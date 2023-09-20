NAME = push_swap

SRC = main.c utility.c utility2.c errors.c sorter.c rotates.c \
swap.c sort_three.c push.c sort_five.c sort_array.c sort_big.c 

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME):
	${MAKE} -C libft
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@/bin/rm -f $(OBJ)
	@${MAKE} -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean

re: 
	make fclean
	make all

.PHONY: all clean fclean re