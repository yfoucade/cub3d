/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:45:58 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 18:35:03 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_game *game, int row, int col, int hex)
{
	char	*pixel_addr;

	pixel_addr = game->mlx.curr_frame.data_addr;
	pixel_addr += row * game->mlx.curr_frame.size_line;
	pixel_addr += col * game->mlx.curr_frame.bits_per_pixel / 8;
	*(int *)pixel_addr = hex;
}

int	ft_get_pixel(t_img	img, int row, int col)
{
	char	*pixel_addr;

	pixel_addr = img.data_addr;
	pixel_addr += row * img.size_line;
	pixel_addr += col * img.bits_per_pixel / 8;
	return (*(int *)pixel_addr);
}

void	create_frame(t_game *game)
{
	game->mlx.curr_frame.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	if (!game->mlx.curr_frame.img_ptr)
	{
		ft_destroy_game(game);
		error_msg("Failed to create image\n", 1);
	}
	game->mlx.curr_frame.data_addr = mlx_get_data_addr(
			game->mlx.curr_frame.img_ptr,
			&game->mlx.curr_frame.bits_per_pixel,
			&game->mlx.curr_frame.size_line,
			&game->mlx.curr_frame.endian
			);
	game->mlx.curr_frame.width = WIN_WIDTH;
	game->mlx.curr_frame.height = WIN_HEIGHT;
}
