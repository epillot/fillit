# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbegne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:10:12 by cbegne            #+#    #+#              #
#    Updated: 2016/11/18 14:01:50 by cbegne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c\
	   read_file.c\
	   is_valid.c\
	   grid.c\
	   solve.c\
	   coo_valid.c\
	   ft_strlen.c\
	   ft_memalloc.c\
	   ft_strnew.c\
	   ft_putstr.c\
	   ft_putendl.c\
	   ft_putchar.c

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAG) $(SRCS)
	$(CC) -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
