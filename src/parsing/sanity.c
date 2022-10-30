/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:51:31 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:59:47 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	is_valid_filename(char *name)
{
	if (!ft_endswith(name, ".cub"))
		return (FALSE);
	return (TRUE);
}

char	is_valid_transition(char old, char new)
{
	if (old == ' ')
		return (ft_is_in_charlist(" 1", new) || new == '\0');
	if (old == '0')
		return (ft_is_in_charlist("01NEWS", new));
	if (old == '1')
		return (TRUE);
	return (new == '0' || new == '1');
}

char	map_is_closed(t_game *game)
{
	int	start_row;
	int	start_col;

	start_row = -1;
	start_col = 0;
	while (++start_row < game->map_height)
		if (check_line(game, start_row, start_col, 0, 1))
			return (FALSE);
	start_row = 0;
	start_col = -1;
	while (++start_col < game->map_width)
		if (check_line(game, start_row, start_col, 1, 0))
			return (FALSE);
	return (TRUE);
}
