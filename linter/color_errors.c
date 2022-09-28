/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:29:26 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 14:29:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_invalid_colors(t_game *game)
{
	if (game->errors & ERR_INV_C)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid C color%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_F)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid F color%s\n",
			RESET, game->filename, RESET);
}
