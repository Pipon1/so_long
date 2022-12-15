# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:12:00 by hefurrer          #+#    #+#              #
#    Updated: 2022/11/08 10:45:11 by hefurrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := so_long
SRC_DIR := src/
OBJ_DIR := obj/
SRC_FILES := main movement map check2d error
LIBFT := libft
SRC := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
CC := gcc -Wall -Werror -Wextra -g

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p obj
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) -L$(LIBFT) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
