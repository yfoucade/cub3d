/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:43:51 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 01:16:54 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_window(t_game *game)
{
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!game->mlx.win_ptr)
	{
		ft_destroy_game(game);
		error_msg("Failed to create window\n", 1);
	}
}

char	init_game_data(t_game *game)
{
	int		row;
	int		col;
	char	player;

	row = -1;
	player = 0;
	while (++row < game->map_height)
	{
		col = -1;
		while (++col < game->map_width)
		{
			if (ft_is_in_charlist("NEWS", game->map[row][col]))
			{
				player = 1;
				if (set_pos_dir_plane(game, row, col))
					return (FAILURE);
			}
		}
	}
	if (!player)
	{
		ft_putstr_fd("Error\nMissing player\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
