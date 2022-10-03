/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:26:44 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 00:31:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/memory.h"
#include "../includes/lists.h"

t_chain_lst	*ft_chain_new(void *content)
{
	t_chain_lst	*new;

	new = (t_chain_lst *) malloc(sizeof(t_chain_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
