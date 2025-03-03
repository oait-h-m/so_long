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

char	**check_map_is_valid(t_map map_coordinates, char **av)
{
	char	**map;

	int y, (x);
	y = 0;
	x = 0;
	map_coordinates.row = count_line(av[1], &map_coordinates.col);
	map = add_map_to_string(map_coordinates.row, map_coordinates.col, av[1]);
	if (!is_map_valid(map, map_coordinates.row, map_coordinates.col, av[1]))
	{
		free_map(map);
		exit(1);
	}
	return (map);
}

void	add_xpm_file_to_images(t_images *images, void *mlx)
{
	int img_height, (img_width);
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

int	handle_key(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->imgs->coin);
		mlx_destroy_image(data->mlx, data->imgs->door);
		mlx_destroy_image(data->mlx, data->imgs->wall);
		mlx_destroy_image(data->mlx, data->imgs->player);
		mlx_destroy_image(data->mlx, data->imgs->empty_space);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map		map_coordinates;
	t_images	img_data;
	t_data		data;
	char		**map;

	if (ac != 2)
		exit(0);
	map_coordinates.col = 0;
	map_coordinates.row = 0;
	map = check_map_is_valid(map_coordinates, av);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1420, 1080, "SO_LONG");
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	add_xpm_file_to_images(&img_data, data.mlx);
	put_images_to_window(map, data.mlx, data.win, img_data);
	free_map(map);
	data.imgs = &img_data;
	mlx_loop(data.mlx);
}
