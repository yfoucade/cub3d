/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:35:21 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 21:06:50 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rc_wall_collision(t_game *game)
{
	double	wall_x;

	if (game->rt_vars.side == 0)
		wall_x = game->player_pos.y
			+ game->rt_vars.perpWallDist * game->rt_vars.ray.y;
	else
		wall_x = game->player_pos.x
			+ game->rt_vars.perpWallDist * game->rt_vars.ray.x;
	return (wall_x - floor(wall_x));
}
