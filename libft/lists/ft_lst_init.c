/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:59:49 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 00:31:55 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/memory.h"
#include "../includes/string.h"

t_chain_lst	*ft_chain_init(void)
{
	t_chain_lst	*lst;

	lst = (t_chain_lst *) malloc(sizeof(t_chain_lst));
	if (!lst)
		return (NULL);
	ft_bzero(lst, sizeof(t_chain_lst));
	return (lst);
}
