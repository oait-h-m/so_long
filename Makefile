# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 17:43:03 by oait-h-m          #+#    #+#              #
#    Updated: 2025/03/10 02:36:02 by oait-h-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wextra -g 

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c libft/ft_putstr_fd.c libft/ft_putnbr.c libft/ft_strcmp.c src/help_fun.c src/floodfill.c src/is_map_valid.c src/check_lines_of_map.c src/handle_keys.c src/put_imgs.c src/move_player.c src/so_long.c


OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ 

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all re fclean clean
