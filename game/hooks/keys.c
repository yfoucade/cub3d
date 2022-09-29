/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:52:36 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 17:55:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "colors.h"
#include "debug.h"

int	ft_key_hook(int keycode, t_game *game)
{
	DEBUG_PRINT(BLUE2"pressed key: %s%d%s for window : %s%p%s\n",
		LIGHTPINK1, keycode, BLUE2, MAGENTA2, game->mlx.win_ptr, RESET);
	return (0);
}