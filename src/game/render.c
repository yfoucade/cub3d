/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:47:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:47:40 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_game *game)
{
	int		col;
	int		row;

	row = -1;
	while (++row < WIN_HEIGHT / 2)
	{
		col = -1;
		while (++col < WIN_WIDTH)
			ft_put_pixel(game, row, col, game->ceiling_color->color_hex);
	}
	--row;
	while (++row < WIN_HEIGHT)
	{
		col = -1;
		while (++col < WIN_WIDTH)
			ft_put_pixel(game, row, col, game->floor_color->color_hex);
	}
}

void	draw_frame(t_game *game)
{
	draw_background(game);
	draw_walls(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.curr_frame.img_ptr, 0, 0);
}
