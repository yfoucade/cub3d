/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:35:55 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 23:12:08 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rc_calc_bounds(t_game *game)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(WIN_HEIGHT / game->rt_vars.perp_wall_dist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	game->rt_vars.draw_start = draw_start;
	game->rt_vars.draw_end = draw_end;
	game->rt_vars.line_height = line_height;
}
