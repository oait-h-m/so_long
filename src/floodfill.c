/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 02:57:59 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/02/28 04:40:17 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

char	**map_copy(char **map, int rows)
{
	char	**cpy_map;
	int		i;

	i = 0;
	cpy_map = malloc(sizeof(char *) * (rows + 1));
	if (!cpy_map)
		return (NULL);
	while (map[i])
	{
		cpy_map[i] = ft_strdup(map[i]);
		if (!cpy_map[i])
		{
			free_map(cpy_map);
			return (NULL);
		}
		i++;
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}

void	find_player(char **map, int *rows, int *columns)
{
	if (!map)
		return ;
	int i, (j);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*rows = i;
				*columns = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

int	check_map_after_flood_fill(char **map)
{
	if (!map)
		return (0);
	int i, (j);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
