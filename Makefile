# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 17:43:03 by oait-h-m          #+#    #+#              #
#    Updated: 2025/02/25 18:01:41 by oait-h-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_strcmp.c  is_map_valid.c main.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJ) 
fclean: clean
	$(RM) $(NAME) 

re: fclean all
