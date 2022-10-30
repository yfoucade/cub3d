/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:35:55 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 18:52:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rc_calc_bounds(t_game *game, int *start, int *end, int *height)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;

	lineHeight = (int)(WIN_HEIGHT / game->rt_vars.perpWallDist);
	drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
	if(drawEnd >= WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
	*start = drawStart;
	*end = drawEnd;
	*height = lineHeight;
}
