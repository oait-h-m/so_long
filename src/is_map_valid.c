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

int is_wall_valid(char **map, int row, int col)
{
    int i, j;
	i = 0;
	while (map[i])
    {
		j = 0;
		while (map[i][j])
        {
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
			{
				if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
					return (0);
			}
            if ((i == 0 || i == row - 1) && map[i][j] != '1' && j < col - 1)
				return (0);
            if ((j == 0 || j == col - 2) && map[i][j] != '1')
				return (0);
			j++;
        }
		i++;
    }
    return (1);
}

int	is_coin_valid(char **map)
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
		write(2, "Error\nNo coins.\n", 16);
		exit(1);
	}
	return (coins);
}

int	is_exit_valid(char **map)
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
	if (exit > 1)
		write(2, "Error Too many doors.\n", 22);
	else if (exit == 0)
		write(2, "Error No doors.\n", 16);
	if (exit != 1)
		return (0);
	return (exit);
}

int	is_player_valid(char **map)
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
	if (player > 1)
		write(2, "Error\nToo many players.\n", 24);
	else if (player == 0)
		write(2, "Error\nNo players.\n", 18);
	if (player != 1)
		return (0);
	return (player);
}

int	is_map_valid(char **map, int row, int col, char *av)
{
	char	**cpy_map;

	int x, (y);
	x = 0;
	y = 0;
	if (!check_name_of_arg(av))
		return (0);
	else if (!is_wall_valid(map, row, col))
		return (0);
	else if (!is_coin_valid(map))
		exit(1);
	else if (!is_exit_valid(map))
		exit(1);
	else if (!is_player_valid(map))
		exit(1);
	find_player(map, &x, &y);
	cpy_map = map_copy(map, row);
	ft_flood_fill(cpy_map, y, x);
	if (!check_map_after_flood_fill(cpy_map))
	{
		free_map(cpy_map);
		return (0);
	}
	free_map(cpy_map);
	return (1);
}
