/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:08:36 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 15:18:52 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lists.h"
#include <stdio.h>

void	ft_buffer_map(t_game *game)
{
	t_chain_lst	*lst;
	t_chain_lst	*tmp;
	int			i;
	int			parameter_line;

	i = 0;
	parameter_line = 6;
	lst = ft_split(game->file_buffer, "\n");
	tmp = lst;
	while (tmp)
	{
		if (parameter_line > 0)
		{
			free(tmp->content);
			ft_chain_pop(&lst, 0);
			parameter_line--;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (is_empty((char *) tmp->content))
		{
			free(tmp->content);
			ft_chain_pop(&lst, i);
		}
		tmp = tmp->next;
		i++;
	}
	game->map_buffer = ft_strjoin("\n", lst);
	ft_chain_clear(&lst);
	ft_chain_clear(&tmp);
}