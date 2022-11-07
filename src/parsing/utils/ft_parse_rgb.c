/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:55:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 01:55:07 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_lst_len(t_str_list *lst)
{
	int	res;

	if (!lst)
		return (0);
	res = 0;
	while (lst)
	{
		lst = lst->next;
		res++;
	}
	return (res);
}

t_color	*ft_parse_rgb(char *s)
{
	t_color		*res;
	t_str_list	*lst;

	lst = ft_split(s, ',');
	if (!lst)
		return (NULL);
	if (ft_lst_len(lst) != 3)
	{
		ft_putstr_fd("Error\nBad number of values in rgb\n", 2);
		return (free_str_list(lst), NULL);
	}
	res = malloc(sizeof(*res));
	if (!res)
		return (free_str_list(lst), NULL);
	if (ft_parse(lst, res))
		return (free_str_list(lst), free(res), NULL);
	free_str_list(lst);
	res->color_hex = (res->r << 16) | (res->g << 8) | res->b;
	return (res);
}
