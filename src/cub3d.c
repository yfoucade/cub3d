/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:48:10 by yfoucade          #+#    #+#             */
/*   Updated: 2022/11/06 22:57:22 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_line(t_game *game, t_img texture)
{
	double	step;
	double	tex_pos;
	int		color;
	int		y;

	step = 1.0 * texture.height / game->rt_vars.line_height;
	tex_pos = (game->rt_vars.draw_start
			- WIN_HEIGHT / 2 + game->rt_vars.line_height / 2) * step;
	y = game->rt_vars.draw_start;
	while (y < game->rt_vars.draw_end)
	{
		game->rt_vars.tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		color = ft_get_pixel(texture, game->rt_vars.tex_y, game->rt_vars.tex_x);
		ft_put_pixel(game, y, game->rt_vars.screen_x, color);
		y++;
	}
}

void	draw_walls(t_game *game)
{
	t_img	texture;
	double	wall_x;

	game->rt_vars.screen_x = -1;
	while (++game->rt_vars.screen_x < WIN_WIDTH)
	{
		rc_set_vars(game);
		rc_distance(game);
		rc_run_dda(game);
		rc_calc_bounds(game);
		texture = get_texture(game);
		wall_x = rc_wall_collision(game);
		game->rt_vars.tex_x = (int)(wall_x * (double)(texture.width));
		if (game->rt_vars.side == 0 && game->rt_vars.ray.x < 0)
			game->rt_vars.tex_x = texture.width - game->rt_vars.tex_x - 1;
		if (game->rt_vars.side == 1 && game->rt_vars.ray.y > 0)
			game->rt_vars.tex_x = texture.width - game->rt_vars.tex_x - 1;
		draw_vertical_line(game, texture);
	}
}
