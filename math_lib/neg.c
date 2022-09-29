/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:55:03 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/28 16:14:24 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	*neg(t_point *a, char free_a)
{
	return (scalar_mul(a, -1, free_a));
}