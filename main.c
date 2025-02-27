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

#include "so_long.h"

void free_map(char **map)
{
	int i;

	i = 0;
	if (!map || !*map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int count_char(char *s, int len)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (i != len)
		return -1;
	return i;
}

int count_line(char *file_d, int *len)
{
	char *s;
	int fd, (count) = 0, (one_time) = 1;
	
	fd = open(file_d, O_RDONLY);
	*len = 0;
	while ((s = get_next_line(fd)))
	{
		if (one_time)
		{
			*len = ft_strlen(s);
			one_time = 0;
		}
		if (count_char(s, *len) == -1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(s);
		count++;
	}
	close (fd);
	return count;
}

char	**add_map_to_string(int row, int col, char *file_d)
{
	char **map, (*s);
	int i, (j), (fd);

	fd = open(file_d, O_RDONLY);
	map = malloc(sizeof(char *) * row + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		j = 0;
		map[i] = malloc(sizeof(char ) * col + 1);
		if (!map[i])
			return (NULL);
		s = get_next_line(fd);
		while (j < col)
		{
			map[i][j] = s[j];
			j++;
		}
		map[i][j] = '\0';
		i++;
		free(s);
	}
	map[i] = NULL;
	return map;
}

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


int main(int ac, char **av)
{
	s_map	map;
	if (ac != 2)
		return 0;
	map.row	= count_line(av[1], &map.col);
	char **test_map = add_map_to_string(map.row, map.col, av[1]);
	if (is_map_valid(test_map, map.row, map.col))
		printf("map is valid. \n");
	else
		printf("map is not valid. \n");
	free_map(test_map);
}
