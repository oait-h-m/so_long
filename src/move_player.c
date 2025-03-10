/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:16:16 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/09 19:45:45 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	game_over(t_data *data, int new_row, int new_col)
{
	if (data->map[new_row][new_col] == 'E'
		&& data->total_coins == data->coins_collected)
	{
		data->count_moves++;
		ft_putnbr(data->count_moves);
		ft_putstr_fd("\nYou Won!\n", 1);
		free_mlx(data);
		exit(0);
	}
}

void	move_player(t_data *data, int new_row, int new_col)
{
	int	old_row;
	int	old_col;

	if (data->map[new_row][new_col] == '1')
		return ;
	old_row = data->pos_p_row;
	old_col = data->pos_p_col;
	if (data->map[new_row][new_col] == 'C')
		data->coins_collected++;
	if (data->map[new_row][new_col] == 'E'
		&& data->total_coins != data->coins_collected)
		return ;
	game_over(data, new_row, new_col);
	data->count_moves++;
	ft_putnbr(data->count_moves);
	ft_putstr_fd("\n", 1);
	data->map[old_row][old_col] = '0';
	data->map[new_row][new_col] = 'P';
	data->pos_p_row = new_row;
	data->pos_p_col = new_col;
	mlx_put_image_to_window(data->mlx, data->win, data->empty_space, old_col
		* 60, old_row * 60);
	mlx_put_image_to_window(data->mlx, data->win, data->player, new_col * 60,
		new_row * 60);
}
