/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:12:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 17:32:59 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "debug.h"

// XXX: This is a demo function it should be rewritten to render cub3d

void	ft_start_game(t_game *game)
{
	DEBUG_PRINT("Player spawn : %.7f, %.7f\n", game->player_x, game->player_y);
	ft_init_game(game);
}
