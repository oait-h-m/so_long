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
	s = get_next_line(fd);
	while (s)
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
		s = get_next_line(fd);
	}
	close(fd);
	return (count);
}
