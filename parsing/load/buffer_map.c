/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:08:36 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 16:10:05 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lists.h"
#include "string.h"
#include <stdio.h>

void	ft_destroy_old_list(t_chain_lst *old_list)
{
	t_chain_lst	*tmp;

	tmp = old_list;
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	ft_chain_clear(&old_list);
}

void	ft_process_lines(t_game *game, int offset, t_chain_lst *old_list)
{
	t_chain_lst	*tmp;

	ft_destroy_old_list(old_list);
	if ((game->map_size + offset >= game->map_size)
		|| ft_strnlen(game->file_buffer + offset, 3) < 3)
	{
		game->map_buffer = ft_strdup("");
		game->errors |= ERR_MAP_MIS;
		return ;
	}
	game->map_buffer = ft_strdup(game->file_buffer + offset);
	game->map_lines = ft_split(game->map_buffer, "\n");
	tmp = game->map_lines;
	while (tmp)
	{
		ft_rstrip((char *) tmp->content);
		tmp = tmp->next;
	}
}

void	ft_buffer_map(t_game *game)
{
	t_chain_lst	*lst;
	t_chain_lst	*tmp;
	int			offset;
	int			parameter_line;
	int			in_map;

	offset = 0;
	in_map = 0;
	parameter_line = 6;
	lst = ft_split(game->file_buffer, "\n");
	tmp = lst;
	while (tmp)
	{
		if (is_empty((char *) tmp->content) && !in_map)
			offset += ft_strlen((char *) tmp->content) + 1;
		else if (parameter_line > 0)
		{
			offset += ft_strlen((char *) tmp->content) + 1;
			parameter_line--;
		}
		else
			in_map = 1;
		tmp = tmp->next;
	}
	ft_process_lines(game, offset, lst);
}
