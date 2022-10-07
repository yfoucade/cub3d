/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:22:14 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/07 22:28:47 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

t_point	normalize(t_point a)
{
	double	norm_a;

	norm_a = norm(a);
	if (norm_a)
		return (scalar_mul(a, 1.0 / norm_a));
	return (a);
}
