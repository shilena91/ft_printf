# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:56:43 by hopham            #+#    #+#              #
#    Updated: 2019/12/02 18:07:24 by hopham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LIB = libft/libftprintf.a

FLAGS = -Wextra -Werror -Wall -g

SRCS = ./srcs/
C_FUNCTIONS = printf parse parse_convert display_gap treatment display_c display_all
C_FILES = $(addprefix $(SRCS), $(addsuffix .c, $(C_FUNCTIONS)))
OBJ = $(addsuffix .o, $(C_FUNCTIONS))

INCLUDES = -I ./includes/ -I ./libft/includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(C_FILES) $(INCLUDES)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(LIB) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
