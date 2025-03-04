/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:26:03 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/02/25 15:26:51 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

char	**check_map_is_valid(t_data map_coordinates, char **av)
{
	char	**map;

	int y, (x);
	y = 0;
	x = 0;
	map_coordinates.row = count_line(av[1], &map_coordinates.columns);
	map = add_map_to_string(map_coordinates.row, map_coordinates.columns, av[1]);
	if (!is_map_valid(map, map_coordinates.row, map_coordinates.columns, av[1]))
	{
		free_map(map);
		exit(1);
	}
	return (map);
}

void	add_xpm_file_to_images(t_images *images, void *mlx)
{
	int	img_height, (img_width);
	images->wall = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/wall.xpm", &img_width,
			&img_height);
	images->player = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/player_goku.xpm", &img_width,
			&img_height);
	images->coin = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/test_coin.xpm", &img_width,
			&img_height);
	images->empty_space = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/empty_space_black.xpm",
			&img_width, &img_height);
	images->door = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/door.xpm", &img_width,
			&img_height);
}

void	put_images_to_window(char **map, void *mlx, void *win, t_images imgs)
{
	int i, (j);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, imgs.wall, j * 64, i * 64);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, imgs.player, j * 64, i * 64);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, imgs.coin, j * 64, i * 64);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, imgs.empty_space, j * 64, i
					* 64);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, imgs.door, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs->player, x * 64, y * 64);
}

void	draw_empty_space(t_data *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs->empty_space, x * 64, y * 64);
}

void	draw_player_and_space(t_data *data)
{
	int	i, (j);
	
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				draw_player(data, j, i);
			else if (data->map[i][j] == '0')
				draw_empty_space(data, j, i);
			j++;
		}
		i++;
	}
}

void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs->coin);
	mlx_destroy_image(data->mlx, data->imgs->door);
	mlx_destroy_image(data->mlx, data->imgs->wall);
	mlx_destroy_image(data->mlx, data->imgs->player);
	mlx_destroy_image(data->mlx, data->imgs->empty_space);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void move_player(t_data *data, int new_row, int new_col)
{
    if (data->map[new_row][new_col] == '1')
        return; 

    data->map[data->row][data->columns] = '0'; 
    if (data->map[new_row][new_col] == 'C')
        data->coins_collected++;
    data->map[new_row][new_col] = 'P'; 
    data->row = new_row;
    data->columns = new_col;

    draw_player_and_space(data);
}

int handle_keys(int key, t_data *data)
{
    if (key == XK_a) 
        move_player(data, data->pos_player_col, data->pos_player_col - 1);
    else if (key == XK_d)
		move_player(data, data->pos_player_row, data->pos_player_col + 1);
    else if (key == XK_w)
        move_player(data, data->pos_player_row - 1, data->pos_player_col);
    else if (key == XK_s) 
        move_player(data, data->pos_player_row + 1, data->pos_player_col);
    else if (key == XK_Escape)  
	{
        free_mlx(data);
        exit(0);
    }
    return (0);
}

int	close_win(t_data *data)
{
	free_mlx(data);
	exit(0);
	return (0);
}

int	find_row_player(char **map)
{
	int i, j;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return i;
			j++;
		}
		i++;
	}
	return 0;
}

int	find_col_player(char **map)
{
	int i, j;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return j;
			j++;
		}
		i++;
	}
	return 0;
}
int	main(int ac, char **av)
{
	t_images	img_data;
	t_data		data;

	if (ac != 2)
		exit(0);
	data.row = 0;
	data.columns = 0;

	
	data.map = check_map_is_valid(data, av);
	data.pos_player_row = find_row_player(data.map);
	data.pos_player_col = find_col_player(data.map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1420, 1080, "SO_LONG");
	add_xpm_file_to_images(&img_data, data.mlx);
	data.imgs = &img_data;
	put_images_to_window(data.map, data.mlx, data.win, img_data);
	mlx_key_hook(data.win, handle_keys, &data);
	mlx_loop(data.mlx);
}
