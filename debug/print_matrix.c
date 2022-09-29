/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:55:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 14:53:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "colors.h"
#include <stdio.h>

void	ft_print_colored(char c)
{
	if (c == EMPTY)
		printf("%s%d%s", GREY46, c, RESET);
	else if (c == WALL)
		printf("%s%d%s", MAGENTA2, c, RESET);
	else if (c == VOID)
		printf("%s%d%s", MAROON, c, RESET);
	else if (c == PLAYER_NORTH)
		printf("%s%d%s", LIGHTGREEN1, c, RESET);
	else if (c == PLAYER_SOUTH)
		printf("%s%d%s", LIGHTGREEN1, c, RESET);
	else if (c == PLAYER_EAST)
		printf("%s%d%s", LIGHTGREEN1, c, RESET);
	else if (c == PLAYER_WEST)
		printf("%s%d%s", LIGHTGREEN1, c, RESET);
	else if (c < 0)
		printf("%s?%s", RED2, RESET);
}

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
			ft_print_colored(ft_get_matrix(matrix, y, x));
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
}
