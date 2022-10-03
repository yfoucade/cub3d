/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:25:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 12:07:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	ft_set_matrix(t_matrix *matrix, int x, int y, char val)
{
	if (x < 0 || x >= matrix->rows || y < 0 || y >= matrix->cols)
		return (-128);
	matrix->matrix[x * matrix->cols + y] = val;
	return (val);
}
