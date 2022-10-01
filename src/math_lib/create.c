/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:48 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/28 16:25:48 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	*create(double x, double y)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	if (res)
	{
		res->x = x;
		res->y = y;
	}
	return (res);
}
