/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:44:36 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/28 16:11:09 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	*add(t_point *a, t_point *b, char free_a, char free_b)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	if (free_a)
		free(a);
	if (free_b)
		free(b);
	return (res);
}
