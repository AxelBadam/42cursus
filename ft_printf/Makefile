# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 17:46:52 by atuliara          #+#    #+#              #
#    Updated: 2022/11/28 12:37:04 by atuliara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

CC = cc

SRCS = ./ft_hex.c ./ft_print_p.c ./ft_printf_utils.c ./ft_printf.c ./ft_uitoa.c ./libft/ft_itoa.c ./libft/ft_putchar_fd.c

OBJS = $(SRCS:.c=.o)  

CFLAGS =-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	
	make fclean -C ./libft
	rm -f $(NAME) *.o
	

re: fclean all
