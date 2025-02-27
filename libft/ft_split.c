/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:36:03 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/11/01 04:36:05 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static void	*ft_free_sp(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

static int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static char	**ft_charge_result(int words, char const *s, char c, char **result)
{
	int	i;
	int	length;
	int	j;

	i = 0;
	while (i < words)
	{
		j = 0;
		while (*s == c)
			s++;
		length = ft_len(s, c);
		result[i] = malloc((length + 1) * sizeof(char));
		if (result[i] == NULL)
			return (ft_free_sp(result, i - 1));
		while (j < length)
		{
			result[i][j] = s[j];
			j++;
		}
		result[i++][length] = '\0';
		s = s + length;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = ft_count_word(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	return (ft_charge_result(words, s, c, result));
}
