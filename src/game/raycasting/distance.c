/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:27:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 23:14:32 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_delta_dist(double *target, double *ray)
{
	if (*ray)
		*target = ft_abs(1 / *ray);
	else
		*target = 1e10;
}

char	ft_sign(double x)
{
	if (x < 0)
		return (-1);
	return (1);
}

void	rc_distance(t_game *game)
{
	set_delta_dist(&game->rt_vars.delta_dist.x, &game->rt_vars.ray.x);
	set_delta_dist(&game->rt_vars.delta_dist.y, &game->rt_vars.ray.y);
	game->rt_vars.step_x = ft_sign(game->rt_vars.ray.x);
	game->rt_vars.step_y = ft_sign(game->rt_vars.ray.y);
	if (game->rt_vars.ray.x < 0)
		game->rt_vars.side_dist.x
			= (game->player_pos.x - game->rt_vars.map_x)
			* game->rt_vars.delta_dist.x;
	else
		game->rt_vars.side_dist.x
			= (game->rt_vars.map_x + 1.0 - game->player_pos.x)
			* game->rt_vars.delta_dist.x;
	if (game->rt_vars.ray.y < 0)
		game->rt_vars.side_dist.y
			= (game->player_pos.y - game->rt_vars.map_y)
			* game->rt_vars.delta_dist.y;
	else
		game->rt_vars.side_dist.y
			= (game->rt_vars.map_y + 1.0 - game->player_pos.y)
			* game->rt_vars.delta_dist.y;
}
