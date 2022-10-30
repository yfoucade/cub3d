/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:53:56 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:54:10 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_str_list	*ft_split(char *str, char c)
{
	t_str_list	*res;
	char		*end;

	if (!str)
		return (NULL);
	res = NULL;
	while (*str)
	{
		end = str;
		while (*end && *end != c)
			++end;
		if (lst_add_n(&res, str, end))
		{
			free_str_list(res);
			return (NULL);
		}
		str = end + (*end == c);
	}
	return (res);
}
