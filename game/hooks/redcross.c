/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redcross.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:17:12 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 17:49:39 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "printf.h"
#include "colors.h"
#include "debug.h"

int	ft_redcross(t_game *game)
{
	ft_printf(LIGHTGREEN2"Exiting cub3d o7 !%s\n", RESET);
	DEBUG_PRINT("mlx_ptr: %p\n", game->mlx.mlx_ptr);
	mlx_loop_end(game->mlx.mlx_ptr);
	return (0);
}