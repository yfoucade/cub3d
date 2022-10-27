/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:09:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/27 12:13:16 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_mlx(t_game *game)
{
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.no_img.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.no_img.img_ptr);
	if (game->mlx.so_img.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.so_img.img_ptr);
	if (game->mlx.we_img.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.we_img.img_ptr);
	if (game->mlx.ea_img.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.ea_img.img_ptr);
	if (game->mlx.curr_frame.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.curr_frame.img_ptr);
	if (game->mlx.mlx_ptr)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
}

void	ft_destroy_game(t_game *game)
{
	DEBUG_PRINT("game : %p\n", game);
	ft_destroy_mlx(game);
	if (game->map_lines)
		free_str_list(game->map_lines);
}
