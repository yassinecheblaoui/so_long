# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 16:05:29 by yachebla          #+#    #+#              #
#    Updated: 2023/09/05 14:33:24 by yachebla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

MLX = -lmlx -framework OpenGL -framework AppKit

FILES = so_long_utilise.c so_long.c check_map.c read_map.c mlx.c mouve_p.c check.c\
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

 OBJ = $(FILES:.c=.o)
 
 all: $(NAME)
 
 $(NAME): $(OBJ) $(HEADER)
		 $(CC) $(CFLAGS) $(MLX) $(FILES) -o $(NAME)
	
clean: 
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re : fclean all