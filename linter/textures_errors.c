/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:28:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 14:29:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_invalid_textures(t_game *game)
{
	if (game->errors & ERR_INV_NO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid NO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_SO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid SO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_WE)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid WE texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_EA)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid EA texture%s\n",
			RESET, game->filename, RESET);
}
