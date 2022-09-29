/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:23:09 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/29 15:57:12 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	norm(t_point *a, char free_byte)
{
	double	res;

	if (!a)
		return (-1);
	res = sqrt(pow(a->x, 2) + pow(a->y, 2));
	if (free_byte & FREE_A)
		free(a);
	return (res);
}
