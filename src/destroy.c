/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:09:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/07 12:21:10 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_mlx(t_game *game)
{
	DEBUG_PRINT("mlx_ptr : %p\n", game->mlx.mlx_ptr);
	DEBUG_PRINT("win_ptr : %p\n", game->mlx.win_ptr);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.no_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.no_img);
	if (game->mlx.so_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.so_img);
	if (game->mlx.we_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.we_img);
	if (game->mlx.ea_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.ea_img);
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
