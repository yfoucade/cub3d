/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:27:06 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/01 20:50:02 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "debug.h"

int	ft_count_seq(char *s)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			n++;
		else
			break ;
		i++;
	}
	if (i > 0)
		return (n);
	else
		return (-1);
}

int	ft_find_shortest_seq(t_chain_lst *lines)
{
	int			candidate;
	int			min;
	t_chain_lst	*tmp;

	tmp = lines;
	candidate = 0;
	min = 2147483647;
	while (tmp)
	{
		candidate = ft_count_seq((char *) tmp->content);
		if (candidate < min && candidate > 0)
			min = candidate;
		if (min == 0)
			break ;
		tmp = tmp->next;
	}
	return (min);
}
