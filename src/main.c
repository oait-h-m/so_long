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

char	**fun(t_map map, char **av)
{
	char	**test_map;

	int y, (x);
	y = 0;
	x = 0;
	map.row = count_line(av[1], &map.col);
	test_map = add_map_to_string(map.row, map.col, av[1]);
	if (is_map_valid(test_map, map.row, map.col, av[1]))
		printf("map is valid. \n");
	else
	{
		exit(1);
		printf("map is not valid. \n");
	}
	return test_map;
}

int	main(int ac, char **av)
{
	t_map	mmap;
	t_data	data;
	void	*mlx = NULL;
	void	*win;
	int img_height, img_width;

	mmap.col = 0;
	mmap.row = 0;

	if (ac != 2)
		exit(1);
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 2920, 1480, "SO_LONG");

	data.wall_img = mlx_xpm_file_to_image(mlx, "/home/oait-h-m/cursus/so_long/src/wall.xpm", &img_width, &img_height);
	data.player_img = mlx_xpm_file_to_image(mlx, "/home/oait-h-m/cursus/so_long/src/Char_3.xpm", &img_width, &img_height);
	data.coin_img = mlx_xpm_file_to_image(mlx, "/home/oait-h-m/cursus/so_long/src/coin1.xpm", &img_width, &img_height);
	data.empty_space_img = mlx_xpm_file_to_image(mlx, "/home/oait-h-m/cursus/so_long/src/emty_space.xpm", &img_width, &img_height);
	data.coin_img = mlx_xpm_file_to_image(mlx, "/home/oait-h-m/cursus/so_long/src/coin1.xpm", &img_width, &img_height);

	char **map = fun(mmap, av);
	int i = 0, j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, data.wall_img, j * 64, i * 64);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, data.player_img, j * 64, i * 64);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, data.coin_img, j * 64, i * 64);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, data.empty_space_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
