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

void	fun(t_map map, char **av)
{
	char	**test_map;

	int y, (x);
	y = 0;
	x = 0;
	map.row = count_line(av[1], &map.col);
	test_map = add_map_to_string(map.row, map.col, av[1]);
	if (is_map_valid(test_map, map.row, map.col, av[1]))
	{
		printf("map is valid. \n");
		exit(1);
	}
	else
		printf("map is not valid. \n");
	free_map(test_map);
}

int	main(int ac, char **av)
{
	t_map	mmap;
	/*void	*mlx;*/
	/*void	*mlx_win;*/

	mmap.col = 0;
	mmap.row = 0;
	if (ac != 2)
		exit(1);
	fun(mmap, av);
	/*mlx = mlx_init();*/
	/*mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");*/
	/*mlx_loop(mlx);*/
}
