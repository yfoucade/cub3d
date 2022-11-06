/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:48:10 by yfoucade          #+#    #+#             */
/*   Updated: 2022/11/06 22:31:13 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_game *game)
{
	int		draw_start;
	int		draw_end;
	int		line_height;
	t_img	texture;
	double	wall_x;

	game->rt_vars.screen_x = -1;
	while (++game->rt_vars.screen_x < WIN_WIDTH)
	{
		rc_set_vars(game);
		rc_distance(game);
		rc_run_dda(game);
		rc_calc_bounds(game, &draw_start, &draw_end, &line_height);
		texture = get_texture(game);
		wall_x = rc_wall_collision(game);
		int	tex_x = (int)(wall_x * (double)(texture.width));
		if (game->rt_vars.side == 0 && game->rt_vars.ray.x < 0)
			tex_x = texture.width - tex_x - 1;
		if (game->rt_vars.side == 1 && game->rt_vars.ray.y > 0)
			tex_x = texture.width - tex_x - 1;
		double	step = 1.0 * texture.height / line_height;
		double	tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			int	tex_y = (int)tex_pos & (texture.height - 1);
			tex_pos += step;
			int	color = ft_get_pixel(texture, tex_y, tex_x);
			ft_put_pixel(game, y, game->rt_vars.screen_x, color);
		}
	}
}
