/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:48:49 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/01 23:11:08 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

t_point	*rot(t_point *a, double theta, char free_byte)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	if (res)
	{
		res->x = a->x * cos(theta) + a->y * sin(theta);
		res->y = a->y * cos(theta) - a->x * sin(theta);
	}
	if (free_byte & FREE_A)
		free(a);
	return (res);
}
