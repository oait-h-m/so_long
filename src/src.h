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

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**map;
	void	*win;
	void	*mlx;
	void	*wall;
	void	*coin;
	void	*door;
	void	*empty_space;
	void	*player;
	int		pos_p_row;
	int		pos_p_col;
	int		len_row;
	int		len_col;
	int		count_moves;
	int		coins_collected;
	int		total_coins;
}			t_data;

void		free_map(char **map);
int			count_line(char *file_d, int *len);
char		**add_map_to_string(int row, int col, char *file_d);
void		check_name_of_arg(char *av);

int			is_wall_valid(char **map, int row, int col);
void		is_coin_valid(char **map);
void		is_exit_valid(char **map);
void		is_player_valid(char **map);
int			is_map_valid(char **map, int row, int col);

char		**map_copy(char **map, int rows);
char		**add_map_to_double_array(char **map, int fd, int row, int col);
void		ft_flood_fill(char **map, int x, int y);
int			find_player(char **map, int *rows, int *columns);
int			check_map_after_flood_fill(char **map);

void		count_coins(t_data *data);
int			count_line_without_new_line(char *s);
void		is_map_rectangle(char **map);
char		**check_map_is_valid(t_data *map_coordinates, char **av);

int			handle_keys(int key, t_data *data);
int			close_win(t_data *data);
void		free_mlx(t_data *data);
void		add_xpm_file_to_images(t_data *data);
void		put_images_to_window(t_data *data);
void		move_player(t_data *data, int new_row, int new_col);

void		put_wall_to_win(t_data *data, int col, int row);
void		put_player_to_win(t_data *data, int col, int row);
void		game_over(t_data *data, int new_row, int new_col);

#endif
