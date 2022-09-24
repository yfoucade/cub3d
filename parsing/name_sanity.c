/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_sanity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:52:54 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/24 23:26:09 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cub3d files must start with whatever, and end in .cub
// todo : insensitive to case check ?

#include "parsing.h"

/**
 * @brief Checks if the file name is valid (ends in .cub)
 * 
 * @param filename Name of the file to check
 * @param game Pointer to the game structure
 * @return int 1 if the name is valid, 0 otherwise
 */
int	ft_name_sanity(char *filename, t_game *game)
{
	if (!ft_endswith(filename, ".cub"))
	{
		game->errors |= ERR_NAME;
		return (0);
	}
	return (1);
}
