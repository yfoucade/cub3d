/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:48:49 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/07 21:12:35 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

/** Clockwise rotation **/
t_point	rot(t_point a, double theta)
{
	t_point	res;

	res.x = a.x * cos(theta) - a.y * sin(theta);
	res.y = a.y * cos(theta) + a.x * sin(theta);
	return (res);
}
