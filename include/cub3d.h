/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:49:36 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/29 15:59:40 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

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
t_point	*add(t_point *a, t_point *b, char free_byte);
t_point	*copy(t_point *a);
t_point	*create(double x, double y);
double	dist(t_point *a, t_point *b, char free_byte);
t_point	*neg(t_point *a, char free_byte);
double	norm(t_point *a, char free_byte);
t_point	*rot(t_point *a, double theta, char free_byte);
t_point	*scalar_mul(t_point *a, double val, char free_byte);
t_point	*sub(t_point *a, t_point *b, char free_byte);

#endif