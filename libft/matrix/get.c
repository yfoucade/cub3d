/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:23:38 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 23:37:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	ft_get_matrix(t_matrix *matrix, int x, int y)
{
	if (x < 0 || x >= matrix->rows || y < 0 || y >= matrix->cols)
		return (-2147483648);
	return (matrix->matrix[x * matrix->cols + y]);
}
