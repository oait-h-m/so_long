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
		exit(1);
	return (map);
}

void	add_xpm_file_to_images(t_data *data, void *mlx)
{
	int img_height, img_width;
	data->wall_img = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/wall.xpm", &img_width,
			&img_height);
	data->player_img = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/player_goku.xpm", &img_width,
			&img_height);
	data->coin_img = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/test_coin.xpm", &img_width,
			&img_height);
	data->empty_space_img = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/empty_space_black.xpm",
			&img_width, &img_height);
	data->door_img = mlx_xpm_file_to_image(mlx,
			"/home/oait-h-m/cursus/so_long/src/door.xpm", &img_width,
			&img_height);
}

void	put_images_to_window(char **map, void *mlx, void *win, t_data data)
{
	int i, (j);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, data.wall_img, j * 64, i
					* 64);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, data.player_img, j * 64, i
					* 64);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, data.coin_img, j * 64, i
					* 64);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, data.empty_space_img, j * 64,
					i * 64);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, data.door_img, j * 64, i
					* 64);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_map	map_coordinates;
	t_data	data;
	void	*mlx;
	void	*win;
	char	**map;

	mlx = NULL;
	if (ac != 2)
		exit(1);
	map_coordinates.col = 0;
	map_coordinates.row = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1420, 1080, "SO_LONG");
	map = check_map_is_valid(map_coordinates, av);
	add_xpm_file_to_images(&data, mlx);
	put_images_to_window(map, mlx, win, data);
	mlx_loop(mlx);
}
