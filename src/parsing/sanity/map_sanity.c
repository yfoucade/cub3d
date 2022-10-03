/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sanity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:23:26 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 15:28:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_is_spawn_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	ft_check_spawns(t_game *game)
{
	int				spawn_points;
	register int	is_spawn_char;
	register int	i;
	register char	c;

	spawn_points = 0;
	i = -1;
	while (game->map_buffer[++i])
	{
		c = game->map_buffer[i];
		is_spawn_char = ft_is_spawn_char(c);
		if (is_spawn_char)
			spawn_points++;
		if (spawn_points > 1)
			break ;
	}
	if (spawn_points == 0)
		game->errors |= ERR_NO_SPW;
	else if (spawn_points > 1)
		game->errors |= ERR_MUL_SPW;
}

void	ft_check_cut(t_game *game)
{
	t_chain_lst	*tmp;

	tmp = game->map_lines;
	while (tmp)
	{
		if (is_empty((char *) tmp->content) && tmp->next
			&& !is_empty((char *) tmp->next->content))
		{
			game->errors |= ERR_MAP_HOL;
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_map_sanity(t_game *game)
{
	ft_check_spawns(game);
	ft_check_cut(game);
}
