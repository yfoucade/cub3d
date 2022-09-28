/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:59:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 12:06:31 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "string.h"

t_matrix	ft_create_matrix(int rows, int cols)
{
	t_matrix	matrix;

	matrix.matrix = malloc(sizeof(char) * rows * cols);
	if (matrix.matrix == NULL)
	{
		matrix.rows = -1;
		matrix.cols = -1;
		return (matrix);
	}
	matrix.rows = rows;
	matrix.cols = cols;
	return (matrix);
}
