/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:29:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 14:29:47 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_invalid_settings_error(t_game *game)
{
	if (game->errors & ERR_INV_ODR)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid order in map settings%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_NO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing NO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_SO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing SO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_WE)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing WE texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_EA)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing EA texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_F)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing F color%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_C)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing C color%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_DUP_SET)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Duplicate map settings%s\n",
			RESET, game->filename, RESET);
}
