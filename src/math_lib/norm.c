/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:23:09 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/01 23:11:04 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

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
