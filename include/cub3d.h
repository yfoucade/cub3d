/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:49:36 by yfoucade          #+#    #+#             */
/*   Updated: 2022/09/28 16:26:31 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define FALSE 0
# define TRUE 1

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

// math_lib.c
t_point	*add(t_point *a, t_point *b, char free_a, char free_b);
t_point	*copy(t_point *a);
t_point	*create(double x, double y);
t_point	*neg(t_point *a, char free_a);
t_point	*rot(t_point *a, double theta, char free_a);
t_point	*scalar_mul(t_point *a, double val, char free_a);
t_point	*sub(t_point *a, t_point *b, char free_a, char free_b);

#endif