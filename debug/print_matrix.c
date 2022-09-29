/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:55:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 14:10:36 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

void	ft_print_matrix(t_matrix *matrix)
{
	int	rows;
	int	cols;
	int	x;
	int	y;

	rows = matrix->rows;
	cols = matrix->cols;
	x = 0;
	y = 0;
	while (x < cols)
	{
		while (y < rows)
		{
			printf("%d ", ft_get_matrix(matrix, y, x));
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
}