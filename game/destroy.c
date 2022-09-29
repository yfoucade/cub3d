/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:09:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 18:02:12 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "debug.h"
#include "game.h"
#include "lists.h"

void	ft_destroy_lines(t_chain_lst *map_lines)
{
	t_chain_lst	*tmp;

	tmp = map_lines;
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	ft_chain_clear(&map_lines);
}

void	ft_destroy_mlx(t_game *game)
{
	DEBUG_PRINT("mlx_ptr : %p\n", game->mlx.mlx_ptr);
	DEBUG_PRINT("win_ptr : %p\n", game->mlx.win_ptr);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.no_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.no_img);
	if (game->mlx.so_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.so_img);
	if (game->mlx.we_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.we_img);
	if (game->mlx.ea_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.ea_img);
	if (game->mlx.mlx_ptr)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
}

void	ft_destroy_game(t_game *game)
{
	DEBUG_PRINT("game : %p\n", game);
	ft_destroy_mlx(game);
	free(game->ea_path);
	free(game->so_path);
	free(game->we_path);
	free(game->no_path);
	free(game->file_buffer);
	free(game->map_buffer);
	if (game->map_lines)
		ft_destroy_lines(game->map_lines);
	if (game->matrix.matrix)
		ft_destroy_matrix(game->matrix);
}
