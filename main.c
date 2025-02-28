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

void	free_map(char **map)
{
	int	i;

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

int	count_char(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i != len)
		return (-1);
	return (i);
}

int	count_line(char *file_d, int *len)
{
	char	*s;

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
	close(fd);
	return (count);
}

char	**add_map_to_string(int row, int col, char *file_d)
{
	char	**map, (*s);
	int i, (j), (fd);
	fd = open(file_d, O_RDONLY);
	map = malloc(sizeof(char *) * (row + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * col + 1);
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
	return (map);
}

int	check_name_of_arg(char *av)
{
	if (ft_strlen(av) < 4)
		return (0);
	while (*av != '.')
		av++;
	if (ft_strcmp(av, ".ber") != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;
	char	**test_map;

	int y, (x);
	y = 0, x = 0;
	if (ac != 2)
		return (0);
	map.row = count_line(av[1], &map.col);
	test_map = add_map_to_string(map.row, map.col, av[1]);
	if (is_map_valid(test_map, map.row, map.col, av[1]))
		printf("map is valid. \n");
	else
		printf("map is not valid. \n");
	free_map(test_map);
}
