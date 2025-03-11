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

	check_name_of_arg(av[1]);
	map_coordinates->len_row = count_line(av[1], &map_coordinates->len_col);
	map = add_map_to_string(map_coordinates->len_row, map_coordinates->len_col,
			av[1]);
	if (!map)
	{
		free_map(map);
		exit(1);
	}
	if (!is_map_valid(map, map_coordinates->len_row, map_coordinates->len_col))
	{
		free_map(map);
		ft_putstr_fd("Error\nInvalid map.\n", 2);
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit(0);
	data.count_moves = 0;
	data.len_row = 0;
	data.map = check_map_is_valid(&data, av);
	find_player(data.map, &data.pos_p_row, &data.pos_p_col);
	count_coins(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (data.len_col - 1) * 60, data.len_row
			* 60, "SO_LONG");
	add_xpm_file_to_images(&data);
	put_images_to_window(&data);
	mlx_key_hook(data.win, handle_keys, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
}
