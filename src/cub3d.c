/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:48:10 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/07 18:34:08 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_redcross(t_game *game)
{
	// ft_printf(LIGHTGREEN2"Exiting cub3d o7 !%s\n", RESET);
	// DEBUG_PRINT("mlx_ptr: %p\n", game->mlx.mlx_ptr);
	mlx_loop_end(game->mlx.mlx_ptr);
	return (0);
}

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
	else if (keycode == XK_Left)
		game->pressed_keys.left = state;
	else if (keycode == XK_Right)
		game->pressed_keys.right = state;
}

int	ft_key_press_hook(int keycode, t_game *game)
{
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

void	update_pos(t_game *game)
{
	(void)game;
}

void	update_plane(t_game *game)
{
	// to compute plane, multiply dir by a rotation matrix with param (3*pi/2)
	// then multiply by target_norm / curr_norm to obtain a vector of target_norm.
	(void)game;
}

void	update_pos_dir_plane(t_game	*game)
{
	update_pos(game);
}

void	draw_frame(t_game *game)
{
	(void)game;
}

int	ft_game_loop(t_game *game)
{
	if (key_pressed(game) || game->init_frame)
	{
		printf("updating frame\n");
		game->init_frame = FALSE;
		update_pos_dir_plane(game);
		draw_frame(game);
		// mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		// 		game->mlx.curr_frame, 0, 0);
		// mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.curr_frame);
	}
	return (0);
}

void	create_hooks(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, 17, 0, ft_redcross, game);
	mlx_hook(game->mlx.win_ptr, 2, 1, ft_key_press_hook, game);
	mlx_hook(game->mlx.win_ptr, 3, 2, ft_key_release_hook, game);
	mlx_loop_hook(game->mlx.mlx_ptr, ft_game_loop, game);
}

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

void	run_game(t_game *game)
{
	create_window(game);
	create_hooks(game);
	mlx_loop(game->mlx.mlx_ptr);
}
