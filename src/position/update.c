/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:42:50 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/10 09:09:44 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_plane(t_game *game)
{
	game->camera_plane = get_perp(game->player_dir, GST_PLANE_SIZE);
}

void	update_pos(t_game *game)
{
	t_point	mov;

	mov = create(0, 0);
	if (game->pressed_keys.w)
		mov = add(mov, game->player_dir);
	if (game->pressed_keys.s)
		mov = sub(mov, game->player_dir);
	if (game->pressed_keys.a)
		mov = sub(mov, get_perp(game->player_dir, GST_DIR_SIZE));
	if (game->pressed_keys.d)
		mov = add(mov, get_perp(game->player_dir, GST_DIR_SIZE));
	mov = normalize(mov);
	mov = scalar_mul(mov, GST_MOVE_SPEED);
	handle_collisions(game, &mov);
	game->player_pos = add(game->player_pos, mov);
}

void	update_dir(t_game *game)
{
	if (game->pressed_keys.left && !game->pressed_keys.right)
		game->player_dir = rot(game->player_dir, GST_ROT_SPEED);
	if (game->pressed_keys.right && !game->pressed_keys.left)
		game->player_dir = rot(game->player_dir, -GST_ROT_SPEED);
}

void	update_pos_dir_plane(t_game	*game)
{
	update_pos(game);
	update_dir(game);
	update_plane(game);
}
