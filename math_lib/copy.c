/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:58:17 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/28 15:59:11 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
