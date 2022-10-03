/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:29:26 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 12:16:06 by jallerha         ###   ########.fr       */
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

t_matrix	ft_arbitrary_init_matrix(int rows, int cols, char n)
{
	t_matrix	matrix;
	int			i;

	matrix.matrix = malloc(sizeof(int) * rows * cols);
	if (matrix.matrix == NULL)
	{
		matrix.rows = -1;
		matrix.cols = -1;
		return (matrix);
	}
	else
	{
		matrix.rows = rows;
		matrix.cols = cols;
	}
	i = 0;
	while (i < rows * cols)
	{
		matrix.matrix[i] = n;
		i++;
	}
	return (matrix);
}
