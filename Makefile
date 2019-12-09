# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:56:43 by hopham            #+#    #+#              #
#    Updated: 2019/12/09 01:31:11 by HoangPham        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LIB = libft/libftprintf.a

FLAGS = -Wextra -Werror -Wall -g

SRCS = ./srcs/
C_FUNCTIONS = ft_printf parse parse_convert display_gap treatment display_c \
			display_s display_i display_p display_o display_all \
			display_u display_x display_f \
			parse_len_mod ft_itoa_base parse_precision
C_FILES = $(addprefix $(SRCS), $(addsuffix .c, $(C_FUNCTIONS)))
OBJ = *.o

INCLUDES = -I ./includes/ -I ./libft/includes/

all: $(NAME)

$(NAME):
	gcc $(INCLUDES) -g -o $(NAME) $(LIB) $(C_FILES)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
