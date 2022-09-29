/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:05:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 16:08:29 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_matrix_errors(t_game *game)
{
	if (game->errors & ERR_ILL_CHR)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Illegal character in map%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MTX_INI)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Failed to initialize matrix%s\n",
			RESET, game->filename, RESET);
}
