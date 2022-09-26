/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:08:36 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 22:11:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lists.h"
#include <stdio.h>

void	ft_buffer_map(t_game *game)
{
	t_chain_lst	*lst;
	t_chain_lst	*tmp;
	int			offset;
	int			parameter_line;

	offset = 0;
	parameter_line = 6;
	lst = ft_split(game->file_buffer, "\n");
	tmp = lst;
	while (tmp)
	{
		if (is_empty((char *) tmp->content))
			offset += ft_strlen((char *) tmp->content) + 1;
		else if (parameter_line > 0)
		{
			offset += ft_strlen((char *) tmp->content) + 1;
			parameter_line--;
		}
		free(tmp->content);
		tmp = tmp->next;
	}
	game->map_buffer = game->file_buffer + offset;
	ft_chain_clear(&lst);
}