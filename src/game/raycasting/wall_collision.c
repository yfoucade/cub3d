/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:35:21 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 19:37:54 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rc_wall_collision(t_game *game)
{
	double	wallX;

	if (game->rt_vars.side == 0)
		wallX = game->player_pos.y + game->rt_vars.perpWallDist * game->rt_vars.ray.y;
	else
		wallX = game->player_pos.x + game->rt_vars.perpWallDist * game->rt_vars.ray.x;
	return (wallX - floor(wallX));
}