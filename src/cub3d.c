/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:48:10 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/22 13:55:46 by yfoucade         ###   ########.fr       */
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
	printf("new pos: %f, %f\n", game->player_pos.x, game->player_pos.y);
	print_point("dir = ", game->player_dir, "\n");
	print_point("plane = ", game->camera_plane, "\n");
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

char	is_in_wall(t_game *game, t_point pos)
{
	if (game->map[(int)pos.y][(int)pos.x] == '1')
		return (TRUE);
	return (FALSE);
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
	mov = add(game->player_pos, mov);
	if (!is_in_wall(game, mov))
		game->player_pos = mov;
}

void	update_dir(t_game *game)
{
	if (game->pressed_keys.left && !game->pressed_keys.right)
		game->player_dir = rot(game->player_dir, GST_ROT_SPEED);
	if (game->pressed_keys.right && !game->pressed_keys.left)
		game->player_dir = rot(game->player_dir, -GST_ROT_SPEED);
}

void	update_plane(t_game *game)
{
	// to compute plane, multiply dir by a rotation matrix with param (3*pi/2)
	// then multiply by target_norm / curr_norm to obtain a vector of target_norm.
	game->camera_plane = get_perp(game->player_dir, GST_PLANE_SIZE);
}

void	update_pos_dir_plane(t_game	*game)
{
	update_pos(game);
	update_dir(game);
	update_plane(game);
}

void	ft_put_pixel(t_game *game, int row, int col, int hex)
{
	char	*pixel_addr;

	pixel_addr = game->frame_data.img_addr;
	pixel_addr += row * game->frame_data.size_line;
	pixel_addr += col * game->frame_data.bits_per_pixel / 8;
	*(int *)pixel_addr = hex;
}

void	draw_background(t_game *game)
{
	int		col;
	int		row;

	row = -1;
	while (++row < WIN_HEIGHT / 2)
	{
		col = -1;
		while (++col < WIN_WIDTH)
			ft_put_pixel(game, row, col, game->ceiling_color->color_hex);
	}
	while (++row < WIN_HEIGHT)
	{
		col = -1;
		while (++col < WIN_WIDTH)
			ft_put_pixel(game, row, col, game->floor_color->color_hex);
	}
}

void	draw_walls(t_game *game)
{
	int	x;

	x = -1;
	(void)game;
	while (++x < WIN_WIDTH)
	{
		;
	}
}

void	draw_frame(t_game *game)
{
	draw_background(game);
	draw_walls(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.curr_frame, 0, 0);
}

int	ft_game_loop(t_game *game)
{
	if (key_pressed(game) || game->init_frame)
	{
		// printf("updating frame\n");
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

void	create_frame(t_game *game)
{
	game->mlx.curr_frame = mlx_new_image(game->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	if (!game->mlx.curr_frame)
	{
		ft_destroy_game(game);
		error_msg("Failed to create image\n", 1);
	}
	game->frame_data.img_addr = mlx_get_data_addr(
		game->mlx.curr_frame,
		&game->frame_data.bits_per_pixel,
		&game->frame_data.size_line,
		&game->frame_data.endian
	);
	game->frame_data.width = WIN_WIDTH;
	game->frame_data.height = WIN_HEIGHT;
}

void	run_game(t_game *game)
{
	create_window(game);
	create_frame(game);
	create_hooks(game);
	mlx_loop(game->mlx.mlx_ptr);
}
