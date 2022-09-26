/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:29:26 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 23:37:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "string.h"

t_matrix	ft_init_matrix(int rows, int cols)
{
	t_matrix	matrix;

	matrix.matrix = malloc(sizeof(int) * rows * cols);
	if (matrix.matrix == NULL)
	{
		matrix.rows = -1;
		matrix.cols = -1;
	}
	else
	{
		matrix.rows = rows;
		matrix.cols = cols;
		ft_bzero(matrix.matrix, sizeof(int) * rows * cols);
	}
	return (matrix);
}
