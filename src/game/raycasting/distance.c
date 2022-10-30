/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:27:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 18:28:51 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rc_distance(t_game *game)
{
	if (game->rt_vars.ray.x)
		game->rt_vars.deltaDist.x = ft_abs(1 / game->rt_vars.ray.x);
	else
		game->rt_vars.deltaDist.x = 1e10;
	if (game->rt_vars.ray.y)
		game->rt_vars.deltaDist.y = ft_abs(1 / game->rt_vars.ray.y);
	else
		game->rt_vars.deltaDist.y = 1e10;
	if (game->rt_vars.ray.x < 0)
	{
		game->rt_vars.stepX = -1;
		game->rt_vars.sideDist.x = (game->player_pos.x - game->rt_vars.mapX) * game->rt_vars.deltaDist.x;
	}
	else
	{
		game->rt_vars.stepX = 1;
		game->rt_vars.sideDist.x = (game->rt_vars.mapX + 1.0 - game->player_pos.x) * game->rt_vars.deltaDist.x;
	}
	if (game->rt_vars.ray.y < 0)
	{
		game->rt_vars.stepY = -1;
		game->rt_vars.sideDist.y = (game->player_pos.y - game->rt_vars.mapY) * game->rt_vars.deltaDist.y;
	}
	else
	{
		game->rt_vars.stepY = 1;
		game->rt_vars.sideDist.y = (game->rt_vars.mapY + 1.0 - game->player_pos.y) * game->rt_vars.deltaDist.y;
	}
}
