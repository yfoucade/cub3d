/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:27:13 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/07 21:31:03 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

t_point	get_perp(t_point a, double target_norm)
{
	a = rot(a, 3 * M_PI / 2);
	a = normalize(a);
	a = scalar_mul(a, target_norm);
	return (a);
}
