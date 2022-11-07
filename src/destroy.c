/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:09:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 01:26:31 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	ft_destroy_colors(t_game *game)
{
	if (game->floor_color)
		free(game->floor_color);
	if (game->ceiling_color)
		free(game->ceiling_color);
}

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
	ft_destroy_mlx(game);
	ft_destroy_map(game);
	ft_destroy_colors(game);
	if (game->map_lines)
		free_str_list(game->map_lines);
}
