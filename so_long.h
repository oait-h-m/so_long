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

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "src/src.h"

typedef struct s_data
{
	void	*wall_img;
	void	*player_img;
	void	*coin_img;
	void	*empty_space_img;
}t_data;

#endif
