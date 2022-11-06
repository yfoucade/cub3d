/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:25:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 20:24:08 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rc_set_vars(t_game *game)
{
	game->rt_vars.hit = 0;
	game->rt_vars.camera_x = 2 * game->rt_vars.screen_x / (double)WIN_WIDTH - 1;
	game->rt_vars.ray = add(
			game->player_dir,
			scalar_mul(game->camera_plane, game->rt_vars.camera_x));
	game->rt_vars.mapX = (int)game->player_pos.x;
	game->rt_vars.mapY = (int)game->player_pos.y;
}
