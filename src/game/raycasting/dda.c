/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:30:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 18:35:47 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rc_run_dda(t_game *game)
{
	while (game->rt_vars.hit == 0)
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
		if (game->map[game->rt_vars.mapY][game->rt_vars.mapX] == '1')
			game->rt_vars.hit = 1;
	}
}
