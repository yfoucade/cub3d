/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:30:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 22:30:53 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_next_square(t_game *game)
{
	if (game->rt_vars.sideDist.x < game->rt_vars.sideDist.y)
	{
		game->rt_vars.sideDist.x += game->rt_vars.deltaDist.x;
		game->rt_vars.mapX += game->rt_vars.stepX;
		game->rt_vars.side = 0;
	}
	else
	{
		game->rt_vars.sideDist.y += game->rt_vars.deltaDist.y;
		game->rt_vars.mapY += game->rt_vars.stepY;
		game->rt_vars.side = 1;
	}
}

void	rc_run_dda(t_game *game)
{
	while (game->rt_vars.hit == 0)
	{
		check_next_square(game);
		if (game->map[game->rt_vars.mapY][game->rt_vars.mapX] == '1')
			game->rt_vars.hit = 1;
	}
	if (game->rt_vars.side == 0)
		game->rt_vars.perpWallDist
			= (game->rt_vars.sideDist.x - game->rt_vars.deltaDist.x);
	else
		game->rt_vars.perpWallDist
			= (game->rt_vars.sideDist.y - game->rt_vars.deltaDist.y);
}
