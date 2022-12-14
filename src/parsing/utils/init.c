/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:55:47 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 01:07:23 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_ptr(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		error_msg("Failed to initialize mlx\n", 1);
}

char	init_empty_map(t_game *game)
{
	int	i;

	if (game->map_height < 3 || game->map_width < 3)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		return (FAILURE);
	}
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (FAILURE);
	ft_bzero(game->map, sizeof(char *) * (game->map_height + 1));
	i = -1;
	while (++i < game->map_height)
	{
		game->map[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[i])
			return (free_array(game->map), FAILURE);
		ft_memset(game->map[i], ' ', game->map_width);
		game->map[i][game->map_width] = '\0';
	}
	return (SUCCESS);
}
