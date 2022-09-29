/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:00:00 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/29 16:14:50 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	*sub(t_point *a, t_point *b, char free_byte)
{
	t_point	*minus_b;
	
	minus_b = neg(b, (free_byte & FREE_B) >> 1);
	return (add(a, minus_b, free_byte | 0b10));
}
