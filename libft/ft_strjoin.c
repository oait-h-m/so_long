/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 06:07:31 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/10/31 06:07:33 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*upd_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*result;

	if (!s2)
		return (s1);
	len = ft_len(s1) + ft_len(s2);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		result[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[i + j] = s2[i];
		i++;
	}
	result[i + j] = '\0';
	return (result);
}
