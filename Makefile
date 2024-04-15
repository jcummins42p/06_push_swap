# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcummins <jcummins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 18:08:59 by jcummins          #+#    #+#              #
#    Updated: 2024/04/15 16:47:29 by jcummins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER_DIR = include
SRC_DIR = srcs
OBJ_DIR = obj
BONUS = checker
BSRC_DIR = bonus
BOBJ_DIR = obj_bonus
CC = cc
CFLAGS = -g -Werror -Wextra -Wall -pedantic -I$(HEADER_DIR)
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
B_SRCS = $(shell find $(BSRC_DIR) -name '*.c')
B_OBJS = $(B_SRCS:$(BSRC_DIR)/%.c=$(BOBJ_DIR)/%.o)
LIB = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing all object files"
	@rm -rf $(OBJ_DIR) $(BOBJ_DIR)
	@rm -rf *.so

fclean: clean
	@echo "Removing all object files and executable"
	@rm -rf $(NAME) $(BONUS)
	@rm -rf *.out
	@rm -rf *.txt
	@rm -rf push_swap checker

re:	fclean all

bonus: $(BONUS)

$(BONUS): $(B_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BOBJ_DIR)/%.o:	$(BSRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

re_bonus: fclean bonus

.PHONY: all clean fclean re
