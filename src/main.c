/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:26:03 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/06 04:06:19 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

char	**check_map_is_valid(t_data *map_coordinates, char **av)
{
	char	**map;

	map_coordinates->len_row = count_line(av[1], &map_coordinates->len_col);
	map = add_map_to_string(map_coordinates->len_row, map_coordinates->len_col, av[1]);
	if (!is_map_valid(map, map_coordinates->len_row, map_coordinates->len_col, av[1]))
	{
		write(2, "Error\nInvalid map.\n", 19); 
		free_map(map);
		exit(1);
	}
	return (map);
}

void	free_mlx(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->door)
		mlx_destroy_image(data->mlx, data->door);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->empty_space)
		mlx_destroy_image(data->mlx, data->empty_space);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	add_xpm_file_to_images(t_data *data)
{
	int	img_height, (img_width);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"/home/oait-h-m/imgs/wall.xpm", &img_width,
			&img_height);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"/home/oait-h-m/imgs/player2.xpm", &img_width,
			&img_height);
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"/home/oait-h-m/imgs/test_coin.xpm", &img_width,
			&img_height);
	data->empty_space = mlx_xpm_file_to_image(data->mlx,
			"/home/oait-h-m/imgs/empty_space_black.xpm",
			&img_width, &img_height);
	data->door = mlx_xpm_file_to_image(data->mlx,
			"/home/oait-h-m/imgs/door.xpm", &img_width,
			&img_height);
	if (!data->wall || !data->player || !data->coin || !data->empty_space || !data->door)
	{
		free_mlx(data);
		exit(1);
	}
}

void	put_images_to_window(t_data *data)
{
	int i, (j);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 64, i * 64);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->player, j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->coin, j * 64, i * 64);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->empty_space, j * 64, i
					* 64);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->door, j * 64, i * 64);
			j++;
		}
		i++;
	}
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
				put_images_to_window(data);
			else if (data->map[i][j] == '0')
				put_images_to_window(data);
			j++;
		}
		i++;
	}
}

void move_player(t_data *data, int new_row, int new_col)
{
    if (data->map[new_row][new_col] == '1')
        return ; 
	else if (data->map[new_row][new_col] == 'C')
		data->coins_collected++;
	else if (data->map[new_row][new_col] == 'E' && data->total_coins == data->coins_collected)
	{
		write(1, "You Won!\n", 9);
		free_mlx(data);
		exit(0);
	}
	if (data->map[new_row][new_col] == 'E' && data->total_coins != data->coins_collected)
		return;
    data->map[data->pos_p_row][data->pos_p_col] = '0'; 
    data->map[new_row][new_col] = 'P'; 
    data->pos_p_row = new_row;
    data->pos_p_col = new_col;

    draw_player_and_space(data);
}

int handle_keys(int key, t_data *data)
{
    if (key == XK_a) 
        move_player(data, data->pos_p_row, data->pos_p_col - 1);
    else if (key == XK_d)
		move_player(data, data->pos_p_row, data->pos_p_col + 1);
    else if (key == XK_w)
        move_player(data, data->pos_p_row - 1, data->pos_p_col);
    else if (key == XK_s) 
        move_player(data, data->pos_p_row + 1, data->pos_p_col);
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

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
		exit(0);

	data.len_row = 0;	
	data.map = check_map_is_valid(&data, av);
	find_player(data.map, &data.pos_p_row, &data.pos_p_col);
	count_coins(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (data.len_col - 1) * 64, data.len_row * 64, "SO_LONG");

	add_xpm_file_to_images(&data);
	put_images_to_window(&data);

	mlx_key_hook(data.win, handle_keys, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);

	mlx_loop(data.mlx);
}
