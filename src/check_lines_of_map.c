/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:39:53 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/02 00:40:05 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	count_char(char *s, int *len)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i != *len)
		return (-1);
	return (i);
}

int	count_line(char *file_d, int *len)
{
	char	*s;

	int fd, (count) = 0;
	fd = open(file_d, O_RDONLY);
	*len = 0;
	s = get_next_line(fd);
	*len = ft_strlen(s);
	while (s)
	{
		free(s);
		count++;
		s = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int strlen_without_new_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	return i;
}

int	is_map_rectangle(char **map)
{
	int	i, (len);

	i = 0;
	len = strlen_without_new_line(map[0]);
	while (map[i])
	{
		if (len != strlen_without_new_line(map[i]))
			return 0;
		i++;
	}
	return 1;
}

void	count_coins(t_data *data)
{
	int	i, (j), (coins);

	i = 0;
	coins = 0;
	data->coins_collected = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	data->total_coins = coins;
}
