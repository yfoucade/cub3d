/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:22:22 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/01 22:12:27 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_check_spawn(t_game *game, char c, int x, int y)
{
	if (ft_is_spawn_char(c))
	{
		game->player_x = x;
		game->player_y = y;
	}
}

char	ft_get_mapped_char(char c)
{
	if (c == '0')
		return ((char) EMPTY);
	else if (c == '1')
		return ((char) WALL);
	else if (c == ' ')
		return ((char) VOID);
	else if (c == 'N')
		return ((char) PLAYER_NORTH);
	else if (c == 'S')
		return ((char) PLAYER_SOUTH);
	else if (c == 'E')
		return ((char) PLAYER_EAST);
	else if (c == 'W')
		return ((char) PLAYER_WEST);
	return (-128);
}

void	ft_fill_matrix(t_game *game)
{
	int			x;
	int			y;
	char		c;
	t_chain_lst	*lst;

	x = 0;
	y = 0;
	lst = game->map_lines;
	while (lst)
	{
		while (x < ft_strlen((char *) lst->content))
		{
			c = ((char *) lst->content)[x];
			ft_set_matrix(&game->matrix, x, y,
				ft_get_mapped_char(c));
			ft_check_spawn(game, c, x, y);
			x++;
		}
		x = 0;
		y++;
		lst = lst->next;
	}
}

void	ft_map_to_matrix(t_game *game)
{
	int			cols;
	int			rows;
	int			candidate;
	t_chain_lst	*lines;

	rows = 0;
	cols = 0;
	lines = game->map_lines;
	while (lines)
	{
		if (!is_empty((char *) lines->content))
		{
			candidate = ft_strlen((char *) lines->content);
			if (candidate > rows)
				rows = candidate;
			cols++;
		}
		lines = lines->next;
	}
	game->matrix = ft_arbitrary_init_matrix(rows, cols, 9);
	if (game->matrix.cols != -1)
		ft_fill_matrix(game);
	else
		game->errors |= ERR_MTX_INI;
}
