/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:11:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/04/12 15:59:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/memory.h"

t_chain_lst	*ft_chain_pop(t_chain_lst **lst, int index)
{
	t_chain_lst	*current;
	t_chain_lst	*next;
	t_chain_lst	*prev;

	if ((*lst)->content == NULL && (*lst)->next == NULL && (*lst)->prev == NULL)
		return (NULL);
	current = *lst;
	prev = NULL;
	while (current)
	{
		next = current->next;
		if (index-- == 0)
		{
			if (prev)
				prev->next = next;
			else
				*lst = next;
			return (current);
		}
		prev = current;
		current = next;
	}
	return (NULL);
}
