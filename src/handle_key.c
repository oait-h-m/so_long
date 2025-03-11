/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:36:02 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/08 04:37:35 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

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
