/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:14:32 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/01 21:20:58 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_img
{
	void		*wall;
	void		*player;
	void		*coin;
	void		*empty_space;
	void		*door;
}				t_images;

typedef struct s_data
{
	char		**map;
	void		*win;
	void		*mlx;
	int			row;
	int			columns;
	int			pos_player_row;
	int			pos_player_col;
	int			coins_collected;
	int			total_coins;
	t_images	*imgs;
}				t_data;

void			free_map(char **map);
int				count_char(char *s, int len);
int				count_line(char *file_d, int *len);
char			**add_map_to_string(int row, int col, char *file_d);
int				check_name_of_arg(char *av);

int				is_wall_valid(char **map, int row, int col);
int				is_coin_valid(char **map);
int				is_exit_valid(char **map);
int				is_player_valid(char **map);
int				is_map_valid(char **map, int row, int col, char *av);

void			flood_fill(char **map, int x, int y);
char			**map_copy(char **map, int rows);
void			find_player(char **map, int *rows, int *columns);
int				check_map_after_flood_fill(char **map);
char			**add_map_to_double_array(char **map, int fd, int row, int col);


void	draw_player_and_space(t_data *data);
void	draw_door(t_data *data, int y, int x);
void	draw_empty_space(t_data *data, int y, int x);
void	draw_coin(t_data *data, int y, int x);
void	draw_wall(t_data *data, int y, int x);
void	draw_player(t_data *data, int y, int x);

#endif
