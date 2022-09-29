/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:22:22 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 14:12:55 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	return (-123);
}

// TODO: Handle matrix init error
void	ft_fill_matrix(t_game *game)
{
	int			x;
	int			y;
	t_chain_lst *lst;

	x = 0;
	y = 0;
	lst = game->map_lines;
	while (lst)
	{
		while (x < ft_strlen((char *) lst->content))
		{
			ft_set_matrix(&game->matrix, x, y, ft_get_mapped_char(((char *) lst->content)[x]));
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

	cols = 0;
	lines = game->map_lines;
	while (lines)
	{
		if (!is_empty((char *) lines->content))
		{
			candidate = ft_strlen((char *) lines->content);
			if (candidate > cols)
				rows = candidate;
			cols++;
		}
		lines = lines->next;
	}
	game->matrix = ft_create_matrix(rows, cols);
	if (game->matrix.cols != -1)
		ft_fill_matrix(game);
}
