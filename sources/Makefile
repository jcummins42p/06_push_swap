# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcummins <jcummins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 18:08:59 by jcummins          #+#    #+#              #
#    Updated: 2024/03/21 15:18:52 by jcummins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.out
HEADER = push_swap.h
CC = cc
CFLAGS = -g -Werror -Wextra -Wall
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIB = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing all object files"
	@rm -rf $(OBJS)
	@rm -rf *.so

fclean: clean
	@echo "Removing all object files and executable"
	@rm -rf $(NAME)
	@rm -rf *.out

re:	fclean all

.PHONY: all clean fclean re
