/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:09:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 14:51:50 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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

void	ft_destroy_game(t_game *game)
{
	free(game->ea_path);
	free(game->so_path);
	free(game->we_path);
	free(game->no_path);
	free(game->file_buffer);
	free(game->map_buffer);
	if (game->map_lines)
		ft_destroy_lines(game->map_lines);
}
