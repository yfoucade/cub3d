/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:32:14 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 23:37:24 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "string.h"

void	ft_destroy_matrix(t_matrix matrix)
{
	if (matrix.matrix != NULL && matrix.rows > 0 && matrix.cols > 0)
	{
		matrix.cols = -1;
		matrix.rows = -1;
		free(matrix.matrix);
	}
}
