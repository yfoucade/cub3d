/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:54:02 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/29 16:10:48 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	*scalar_mul(t_point *a, double val, char free_byte)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	if (res)
	{
		res->x = val * a->x;
		res->y = val * a->y;
	}
	if (free_byte & FREE_A)
		free(a);
	return (res);
}
