/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:32:20 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 14:55:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_map_errors(t_game *game)
{
	if (game->errors & ERR_MUL_SPW)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Multiple spawn points%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_NO_SPW)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' No spawn point%s\n",
			RESET, game->filename, RESET);
}
