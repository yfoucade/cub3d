/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:55:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:55:26 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	*ft_parse_rgb(char *s)
{
	t_color		*res;
	t_str_list	*lst;

	lst = ft_split(s, ',');
	if (!lst)
		return (NULL);
	res = malloc(sizeof(*res));
	if (!res)
		return (free_str_list(lst), NULL);
	if (ft_parse(lst, res))
		return (free_str_list(lst), free(res), NULL);
	free_str_list(lst);
	res->color_hex = (res->r << 16) | (res->g << 8) | res->b;
	return (res);
}
