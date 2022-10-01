/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:26:03 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/01 22:37:39 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This part of the parsing process is important :
// - Reduces memory usage
// - Accelerates the parsing process

#include "lists.h"
#include "parsing.h"

void	ft_remove_spaces(t_chain_lst *lines)
{
	int			shortest_seq;
	t_chain_lst	*tmp;
	char		*old;

	tmp = lines;
	shortest_seq = ft_find_shortest_seq(tmp);
	if (shortest_seq == 0)
		return ;
	while (tmp)
	{
		old = (char *) tmp->content;
		if (!is_empty(old))
		{
			tmp->content = ft_strdup((char *) tmp->content + shortest_seq);
			free(old);
		}
		tmp = tmp->next;
	}
}