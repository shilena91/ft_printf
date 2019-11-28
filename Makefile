# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:56:43 by hopham            #+#    #+#              #
#    Updated: 2019/11/27 13:00:11 by hopham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LIB = libft/libftprintf.a

FLAGS = -Wextra -Werror -Wall

SRCS = srcs/*.c
OBJ = srcs/*.o

INCLUDES = ./includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -I $(INCLUDES) -o $(NAME) $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
