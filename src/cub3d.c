/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:48:10 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/30 23:39:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_game *game)
{
	int		drawStart;
	int		drawEnd;
	int		lineHeight;
	t_img	texture;
	double	wallX;

	game->rt_vars.screen_x = -1;
	while (++game->rt_vars.screen_x < WIN_WIDTH)
	{
		rc_set_vars(game);
		rc_distance(game);
		rc_run_dda(game);
		if(game->rt_vars.side == 0)
			game->rt_vars.perpWallDist = (game->rt_vars.sideDist.x - game->rt_vars.deltaDist.x);
		else
			game->rt_vars.perpWallDist = (game->rt_vars.sideDist.y - game->rt_vars.deltaDist.y);
		rc_calc_bounds(game, &drawStart, &drawEnd, &lineHeight);
		texture = get_texture(game);
		wallX = rc_wall_collision(game);
		int texX = (int)(wallX * (double)(texture.width));
		if(game->rt_vars.side == 0 && game->rt_vars.ray.x < 0) texX = texture.width - texX - 1;
		if(game->rt_vars.side == 1 && game->rt_vars.ray.y > 0) texX = texture.width - texX - 1;
      	double step = 1.0 * texture.height / lineHeight;
      	double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (texture.height - 1);
			texPos += step;
			int color = ft_get_pixel(texture, texY, texX);
			ft_put_pixel(game, y, game->rt_vars.screen_x, color);
		}
	}
}
