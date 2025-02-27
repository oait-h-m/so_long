/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:23:51 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/02/27 01:30:56 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_wall_valid(char **map, int row, int col)
{
	int i, (j);
	i = 0;
	while (map[i])
	{
		j = 0;	
		while (map[i][j])
		{
			if ((i == 0 && map[i][j] != '1' && j < col - 1) || (i == (row - 1) && map[i][j] != '1' && j < col - 1))
				return(0);
			else if ((j == 0 && map[i][j] != '1') || (j == (col - 2) && map[i][j] != '1'))
				return(0);
			j++;
		}
		i++;
	}
	return 1;
}

int is_coin_valid(char **map)
{
	int i, (j), (coins);

	coins = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return coins;
}

int is_exit_valid(char **map)
{
	int i, (j), (exit);

	exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return 0;
	return exit;
}

int is_player_valid(char **map)
{
	int i, (j), (player);

	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return 0;
	return player;
}

int is_map_valid(char **map, int row, int col)
{
	if (!is_wall_valid(map, row, col))
		return (0);
	else if (!is_coin_valid(map))
			return 0;
	else if (!is_exit_valid(map))
			return 0;
	else if (!is_player_valid(map))
			return 0;
	return 1;
}
