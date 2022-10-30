/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:44:58 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:45:05 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game_loop(t_game *game)
{
	if (key_pressed(game) || game->init_frame)
	{
		game->init_frame = FALSE;
		update_pos_dir_plane(game);
		draw_frame(game);
	}
	return (0);
}
