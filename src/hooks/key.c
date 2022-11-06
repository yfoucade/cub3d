/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:35:55 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/06 23:16:05 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_switch_key_state(int keycode, t_game *game, char state)
{
	if (keycode == 'w' || keycode == 'W')
		game->pressed_keys.w = state;
	else if (keycode == 'a' || keycode == 'A')
		game->pressed_keys.a = state;
	else if (keycode == 's' || keycode == 'S')
		game->pressed_keys.s = state;
	else if (keycode == 'd' || keycode == 'D')
		game->pressed_keys.d = state;
	else if (keycode == XK_LEFT)
		game->pressed_keys.left = state;
	else if (keycode == XK_RIGHT)
		game->pressed_keys.right = state;
}

int	ft_key_press_hook(int keycode, t_game *game)
{
	if (keycode == XK_ESCAPE)
		ft_redcross(game);
	ft_switch_key_state(keycode, game, KEY_ON);
	return (0);
}

int	ft_key_release_hook(int keycode, t_game *game)
{
	ft_switch_key_state(keycode, game, KEY_OFF);
	return (0);
}

char	key_pressed(t_game *game)
{
	if (game->pressed_keys.w ^ game->pressed_keys.s)
		return (TRUE);
	if (game->pressed_keys.a ^ game->pressed_keys.d)
		return (TRUE);
	if (game->pressed_keys.left ^ game->pressed_keys.right)
		return (TRUE);
	return (FALSE);
}
