/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:11:28 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 01:03:48 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	set_pos_dir_plane(t_game *game, int row, int col)
{
	if (game->player_pos.x)
		return (FAILURE);
	game->player_pos = create(col * (GST_TILE_SIZE)
			+ .5, row * (GST_TILE_SIZE) + .5);
	if (game->map[row][col] == 'N')
		game->player_dir = create(0, -1);
	if (game->map[row][col] == 'E')
		game->player_dir = create(1, 0);
	if (game->map[row][col] == 'W')
		game->player_dir = create(-1, 0);
	if (game->map[row][col] == 'S')
		game->player_dir = create(0, 1);
	update_plane(game);
	return (SUCCESS);
}

char	textures_set(t_game *game)
{
	if (!game->mlx.no_img.img_ptr)
		return (FALSE);
	if (!game->mlx.so_img.img_ptr)
		return (FALSE);
	if (!game->mlx.ea_img.img_ptr)
		return (FALSE);
	if (!game->mlx.we_img.img_ptr)
		return (FALSE);
	if (!game->floor_color)
		return (FALSE);
	if (!game->ceiling_color)
		return (FALSE);
	return (TRUE);
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

char	add_texture(char *path, t_game *game, t_img *img)
{
	ft_strip(path);
	if (img)
	{
		ft_putstr_fd("Error\nTexture is defined twice\n", 2);
		return (FAILURE);
	}
	img->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&img->width, &img->height);
	if (!img->img_ptr)
	{
		ft_putstr_fd("Error\nCould not load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (FAILURE);
	}
	img->data_addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (SUCCESS);
}

void	fill_map(t_game *game)
{
	char		**tmp_array;
	t_str_list	*tmp_lst;

	tmp_array = game->map;
	tmp_lst = game->map_lines;
	while (tmp_lst)
	{
		ft_memmove(*tmp_array, tmp_lst->str, ft_strlen(tmp_lst->str));
		++tmp_array;
		tmp_lst = tmp_lst->next;
	}
}
