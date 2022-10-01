/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:58:17 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/01 23:09:36 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

t_point	*copy(t_point *a)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	res->x = a->x;
	res->y = a->y;
	return (res);
}
