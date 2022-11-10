/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:42:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/10 09:09:55 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_collisions(t_game *game, t_point *mov)
{
	t_point	new_pos;

	new_pos = add(game->player_pos, create(0, mov->y));
	if (mov->y < 0 && game->map[(int)(new_pos.y - EPS)][(int)new_pos.x] == '1')
		mov->y = 0;
	if (mov->y > 0 && game->map[(int)(new_pos.y + EPS)][(int)new_pos.x] == '1')
		mov->y = 0;
	new_pos = add(game->player_pos, create(mov->x, 0));
	if (mov->x < 0 && game->map[(int)new_pos.y][(int)(new_pos.x - EPS)] == '1')
		mov->x = 0;
	if (mov->x > 0 && game->map[(int)new_pos.y][(int)(new_pos.x + EPS)] == '1')
		mov->x = 0;
}