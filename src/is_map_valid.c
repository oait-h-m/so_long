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

#include "src.h"

int	is_wall_valid(char **map, int row, int col)
{
	int i, (j), (invalid);
	i = 0;
	invalid = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
			{
				if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
					invalid++;
			}
			if ((i == 0 || i == row - 1) && map[i][j] != '1' && j < col - 1)
				invalid++;
			if ((j == 0 || j == col - 2) && map[i][j] != '1')
				invalid++;
			j++;
		}
		i++;
	}
	if (invalid)
		return (0);
	return (1);
}

void	is_coin_valid(char **map)
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
	if (coins == 0)
	{
		ft_putstr_fd("Error\nNo coins.\n", 2);
		free_map(map);
		exit(1);
	}
}

void	is_exit_valid(char **map)
{
	int i, (j), (door);
	door = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				door++;
			j++;
		}
		i++;
	}
	if (door != 1)
	{
		ft_putstr_fd("Error\nNo door or too many doors.\n", 2);
		free_map(map);
		exit(1);
	}
}

void	is_player_valid(char **map)
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
	{
		ft_putstr_fd("Error\n No player or too many players.\n", 2);
		free_map(map);
		exit(1);
	}
}

int	is_map_valid(char **map, int row, int col)
{
	char	**cpy_map;

	int x, (y);
	if (!is_wall_valid(map, row, col))
		return (0);
	is_map_rectangle(map);
	is_coin_valid(map);
	is_exit_valid(map);
	is_player_valid(map);
	find_player(map, &x, &y);
	cpy_map = map_copy(map, row);
	ft_flood_fill(cpy_map, y, x);
	if (!check_map_after_flood_fill(cpy_map))
	{
		free_map(cpy_map);
		return (0);
	}
	free_map(cpy_map);
	cpy_map = NULL;
	return (1);
}
