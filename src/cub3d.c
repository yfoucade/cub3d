/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:48:10 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/24 02:56:22 by yfoucade         ###   ########.fr       */
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
	if (keycode == XK_Escape)
		ft_redcross(game);
	ft_switch_key_state(keycode, game, KEY_ON);
	return (0);
}

int	ft_key_release_hook(int keycode, t_game *game)
{
	ft_switch_key_state(keycode, game, KEY_OFF);
	// printf("new pos: %f, %f\n", game->player_pos.x, game->player_pos.y);
	// print_point("dir = ", game->player_dir, "\n");
	// print_point("plane = ", game->camera_plane, "\n");
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

	pixel_addr = game->mlx.curr_frame.data_addr;
	pixel_addr += row * game->mlx.curr_frame.size_line;
	pixel_addr += col * game->mlx.curr_frame.bits_per_pixel / 8;
	*(int *)pixel_addr = hex;
}

int	ft_get_pixel(t_img	img, int row, int col)
{
	char	*pixel_addr;

	pixel_addr = img.data_addr;
	pixel_addr += row * img.size_line;
	pixel_addr += col * img.bits_per_pixel / 8;
	return *(int *)pixel_addr;
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
	--row;
	while (++row < WIN_HEIGHT)
	{
		col = -1;
		while (++col < WIN_WIDTH)
			ft_put_pixel(game, row, col, game->floor_color->color_hex);
	}
}

t_img	get_texture(t_game *game)
{
	if (game->rt_vars.side == 0)
	{
		if (game->rt_vars.ray.x < 0)
			return (game->mlx.ea_img);
		return (game->mlx.we_img);
	}
	if (game->rt_vars.ray.y < 0)
		return (game->mlx.no_img);
	return (game->mlx.so_img);
}

void	print_trgb(int color)
{
	int	t, r, g, b;

	t = (color >> 24) & 0xff;
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = (color) & 0xff;
	printf("t = %0x, r = %0x, g = %0x, b = %0x\n", t, r, g, b);
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	draw_walls(t_game *game)
{
	game->rt_vars.screen_x = -1;
	while (++game->rt_vars.screen_x < WIN_WIDTH)
	{
		game->rt_vars.hit = 0;
		game->rt_vars.camera_x = 2 * game->rt_vars.screen_x / (double)WIN_WIDTH - 1;
		game->rt_vars.ray = add(game->player_dir, scalar_mul(game->camera_plane, game->rt_vars.camera_x));
		game->rt_vars.mapX = (int)game->player_pos.x;
		game->rt_vars.mapY = (int)game->player_pos.y;
		//length of ray from one x or y-side to next x or y-side
		if (game->rt_vars.ray.x)
			// game->rt_vars.deltaDist.x = sqrt(1 + (game->rt_vars.ray.y * game->rt_vars.ray.y) / (game->rt_vars.ray.x * game->rt_vars.ray.x));
			game->rt_vars.deltaDist.x = ft_abs(1 /  game->rt_vars.ray.x);
		else
			game->rt_vars.deltaDist.x = 1e10;
		if (game->rt_vars.ray.y)
			// game->rt_vars.deltaDist.y = sqrt(1 + (game->rt_vars.ray.x * game->rt_vars.ray.x) / (game->rt_vars.ray.y * game->rt_vars.ray.y));
			game->rt_vars.deltaDist.y = ft_abs(1 /  game->rt_vars.ray.y);
		else
			game->rt_vars.deltaDist.y = 1e10;
		if (game->rt_vars.ray.x < 0)
		{
			game->rt_vars.stepX = -1;
			game->rt_vars.sideDist.x = (game->player_pos.x - game->rt_vars.mapX) * game->rt_vars.deltaDist.x;
		}
		else
		{
			game->rt_vars.stepX = 1;
			game->rt_vars.sideDist.x = (game->rt_vars.mapX + 1.0 - game->player_pos.x) * game->rt_vars.deltaDist.x;
		}
		if (game->rt_vars.ray.y < 0)
		{
			game->rt_vars.stepY = -1;
			game->rt_vars.sideDist.y = (game->player_pos.y - game->rt_vars.mapY) * game->rt_vars.deltaDist.y;
		}
		else
		{
			game->rt_vars.stepY = 1;
			game->rt_vars.sideDist.y = (game->rt_vars.mapY + 1.0 - game->player_pos.y) * game->rt_vars.deltaDist.y;
		}
		//perform DDA
		while (game->rt_vars.hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (game->rt_vars.sideDist.x < game->rt_vars.sideDist.y)
			{
			game->rt_vars.sideDist.x += game->rt_vars.deltaDist.x;
			game->rt_vars.mapX += game->rt_vars.stepX;
			game->rt_vars.side = 0;
			}
			else
			{
			game->rt_vars.sideDist.y += game->rt_vars.deltaDist.y;
			game->rt_vars.mapY += game->rt_vars.stepY;
			game->rt_vars.side = 1;
			}
			//Check if ray has hit a wall
			if (game->map[game->rt_vars.mapY][game->rt_vars.mapX] == '1')
				game->rt_vars.hit = 1;
		}
		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if(game->rt_vars.side == 0)
			game->rt_vars.perpWallDist = (game->rt_vars.sideDist.x - game->rt_vars.deltaDist.x);
		else
			game->rt_vars.perpWallDist = (game->rt_vars.sideDist.y - game->rt_vars.deltaDist.y);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / game->rt_vars.perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawEnd >= WIN_HEIGHT) drawEnd = WIN_HEIGHT - 1;
		t_img	texture = get_texture(game);
		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (game->rt_vars.side == 0)
			wallX = game->player_pos.y + game->rt_vars.perpWallDist * game->rt_vars.ray.y;
		else
			wallX = game->player_pos.x + game->rt_vars.perpWallDist * game->rt_vars.ray.x;
		wallX -= floor((wallX));
		int texX = (int)((1 - wallX) * (double)(texture.width));
		if(game->rt_vars.side == 0 && game->rt_vars.ray.x > 0) texX = texture.width - texX - 1;
		if(game->rt_vars.side == 1 && game->rt_vars.ray.y < 0) texX = texture.width - texX - 1;
		// How much to increase the texture coordinate per screen pixel
      	double step = 1.0 * texture.height / lineHeight;
		// Starting texture coordinate
      	double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
		// printf("here\n");
		// printf("drawing line : %d\n", game->rt_vars.screen_x);
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (texture.height - 1);
			// printf("texY, texX = (%d, %d)\n", texY, texX);
			texPos += step;
			// int	color = *(int*)(texture.data_addr + texture.size_line * texY + texX);
			int color = ft_get_pixel(texture, texY, texX);
			// printf("color = %d\n", color);
			// print_trgb(color);
			ft_put_pixel(game, y, game->rt_vars.screen_x, color);
		}
	}
}

void	draw_frame(t_game *game)
{
	draw_background(game);
	draw_walls(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.curr_frame.img_ptr, 0, 0);
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
	game->mlx.curr_frame.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	if (!game->mlx.curr_frame.img_ptr)
	{
		ft_destroy_game(game);
		error_msg("Failed to create image\n", 1);
	}
	game->mlx.curr_frame.data_addr = mlx_get_data_addr(
		game->mlx.curr_frame.img_ptr,
		&game->mlx.curr_frame.bits_per_pixel,
		&game->mlx.curr_frame.size_line,
		&game->mlx.curr_frame.endian
	);
	game->mlx.curr_frame.width = WIN_WIDTH;
	game->mlx.curr_frame.height = WIN_HEIGHT;
}

void	run_game(t_game *game)
{
	create_window(game);
	create_frame(game);
	create_hooks(game);
	mlx_loop(game->mlx.mlx_ptr);
}
