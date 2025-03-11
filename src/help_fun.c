/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:27:47 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/01 21:30:43 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

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

char	**add_map_to_double_array(char **map, int fd, int row, int col)
{
	char	*s;

	int i, (j);
	i = 0;
	while (i < row)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * (col + 1));
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
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

char	**add_map_to_string(int row, int col, char *file_d)
{
	int		fd;
	char	**map;

	fd = open(file_d, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid map.\n", 2);
		return (NULL);
	}
	map = malloc(sizeof(char *) * (row + 1));
	if (!map)
		return (NULL);
	add_map_to_double_array(map, fd, row, col);
	return (map);
}

void	check_name_of_arg(char *av)
{
	if (ft_strlen(av) < 4)
	{
		ft_putstr_fd("Error\nInvalid map.\n", 2);
		exit(1);
	}
	while (*av != '\0' && *av != '.')
		av++;
	if (ft_strcmp(av, ".ber") != 0)
	{
		ft_putstr_fd("Error\nInvalid map.\n", 2);
		exit(1);
	}
}
