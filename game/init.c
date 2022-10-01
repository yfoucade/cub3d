/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:05:04 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/01 22:41:54 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "string.h"
#include "debug.h"
#include "colors.h"

void	ft_init_hooks(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, 17, 0, ft_redcross, game);
	mlx_hook(game->mlx.win_ptr, 2, 1, ft_key_hook, game);
}

void	ft_load_textures(t_game *game)
{
	int	ignore;

	game->mlx.no_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->no_path, &ignore, &ignore);
	game->mlx.so_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->so_path, &ignore, &ignore);
	game->mlx.we_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->we_path, &ignore, &ignore);
	game->mlx.ea_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->ea_path, &ignore, &ignore);
	if (!game->mlx.no_img)
		ft_print_error(game, "Failed to load NO texture", 1);
	if (!game->mlx.so_img)
		ft_print_error(game, "Failed to load SO texture", 1);
	if (!game->mlx.we_img)
		ft_print_error(game, "Failed to load WE texture", 1);
	if (!game->mlx.ea_img)
		ft_print_error(game, "Failed to load EA texture", 1);
}

void	ft_init_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		ft_print_error(game, "Failed to initialize MLX", 1);
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!game->mlx.win_ptr)
		ft_print_error(game, "Failed to create window", 1);
	ft_load_textures(game);
	ft_init_hooks(game);
}

// This function can be removed
void	ft_demo_color(t_game *game)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y < height / 2)
				mlx_pixel_put(game->mlx.mlx_ptr,
					game->mlx.win_ptr, x, y, game->ceiling_color.color_hex);
			else
				mlx_pixel_put(game->mlx.mlx_ptr,
					game->mlx.win_ptr, x, y, game->floor_color.color_hex);
			x++;
		}
		y++;
	}
}

void	ft_init_game(t_game *game)
{
	ft_init_mlx(game);
	ft_demo_color(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.no_img, 0, 0);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.so_img, 64, 64);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.we_img, 128, 128);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.ea_img, 196, 196);
	mlx_loop(game->mlx.mlx_ptr);
}
