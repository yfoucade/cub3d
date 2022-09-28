/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:22:22 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 16:26:51 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "parsing.h"

// TODO: Handle matrix init error
// TODO: Copy map lines to matrix
void	ft_fill_matrix(t_game *game)
{
	
}

t_matrix	ft_map_to_matrix(t_game *game)
{
	int			cols;
	int			rows;
	int			candidate;
	t_chain_lst	*lines;

	rows = 0;
	lines = game->map_lines;
	while (lines)
	{
		if (!is_empty((char *) lines->content))
		{
			candidate = ft_strlen((char *) lines->content);
			if (candidate > cols)
				cols = candidate;
			rows++;
		}
		lines = lines->next;
	}
	game->matrix = ft_create_matrix(rows, cols);
	if (game->matrix.cols != -1)
		ft_fill_matrix(game);
}
