/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:08 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/02/27 02:44:44 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct c_map
{
	int	row;
	int	col;
}		t_map;

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, const char *s2);
char	*upd_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *s1, char *s2);

int		is_wall_valid(char **map, int row, int col);
int		is_coin_valid(char **map);
int		is_exit_valid(char **map);
int		is_player_valid(char **map);
int		is_map_valid(char **map, int row, int col, char *av);
int		check_name_of_arg(char *av);
int		ft_strcmp(char *s1, char *s2);
void	free_map(char **map);

void	flood_fill(char **map, int x, int y);
char	**map_copy(char **map, int rows);
void	find_player(char **map, int *rows, int *columns);
int		check_map_after_flood_fill(char **map);

#endif
