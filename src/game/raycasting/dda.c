/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:30:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 23:13:38 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_next_square(t_game *game)
{
	if (game->rt_vars.side_dist.x < game->rt_vars.side_dist.y)
	{
		game->rt_vars.side_dist.x += game->rt_vars.delta_dist.x;
		game->rt_vars.map_x += game->rt_vars.step_x;
		game->rt_vars.side = 0;
	}
	else
	{
		game->rt_vars.side_dist.y += game->rt_vars.delta_dist.y;
		game->rt_vars.map_y += game->rt_vars.step_y;
		game->rt_vars.side = 1;
	}
}

void	rc_run_dda(t_game *game)
{
	while (game->rt_vars.hit == 0)
	{
		check_next_square(game);
		if (game->map[game->rt_vars.map_y][game->rt_vars.map_x] == '1')
			game->rt_vars.hit = 1;
	}
	if (game->rt_vars.side == 0)
		game->rt_vars.perp_wall_dist
			= (game->rt_vars.side_dist.x - game->rt_vars.delta_dist.x);
	else
		game->rt_vars.perp_wall_dist
			= (game->rt_vars.side_dist.y - game->rt_vars.delta_dist.y);
}
