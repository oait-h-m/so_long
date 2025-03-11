/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:59:45 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/08 21:00:06 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	add_xpm_file_to_images(t_data *data)
{
	int img_height, (img_width);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&img_width, &img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "./textures/player222.xpm",
			&img_width, &img_height);
	data->coin = mlx_xpm_file_to_image(data->mlx, "./textures/ball.xpm",
			&img_width, &img_height);
	data->empty_space = mlx_xpm_file_to_image(data->mlx,
			"./textures/empty_space_black.xpm", &img_width, &img_height);
	data->door = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm",
			&img_width, &img_height);
	if (!data->wall || !data->player || !data->coin || !data->empty_space
		|| !data->door)
	{
		free_mlx(data);
		exit(1);
	}
}

void	put_wall_to_win(t_data *data, int col, int row)
{
	mlx_put_image_to_window(data->mlx, data->win, data->wall, col * 60, row
		* 60);
}

void	put_player_to_win(t_data *data, int col, int row)
{
	mlx_put_image_to_window(data->mlx, data->win, data->player, col * 60, row
		* 60);
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
				put_wall_to_win(data, j, i);
			else if (data->map[i][j] == 'P')
				put_player_to_win(data, j, i);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->coin, j
					* 60, i * 60);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->empty_space,
					j * 60, i * 60);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->door, j
					* 60, i * 60);
			j++;
		}
		i++;
	}
}
