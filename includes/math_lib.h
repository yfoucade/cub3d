/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:01:04 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/07 21:24:54 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_LIB_H
# define MATH_LIB_H

# include <math.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1

# define FREE_A 0b01
# define FREE_B 0b10

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

// math_lib.c
t_point	add(t_point a, t_point b);
t_point	copy(t_point a);
t_point	create(double x, double y);
double	dist(t_point a, t_point b);
double	inner_product(t_point a, t_point b);
t_point	neg(t_point a);
t_point	normalize(t_point a);
double	norm(t_point a);
t_point	rot(t_point a, double theta);
t_point	scalar_mul(t_point a, double val);
t_point	sub(t_point a, t_point b);

#endif