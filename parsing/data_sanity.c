/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sanity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:50:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 00:21:55 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file checks a function that check whether the file contains non-ascii
// data or not, this is used to abort parsing before the parser tries to
// allocate a huge amount of memory for a file that is not a valid map.
// (such as /dev/(u)random or any other kind)

// in order to collect a safe-sample, we will only read 255 bytes in the file
// and check if they are ascii or not.

#include "parsing.h"

/**
 * @brief This function takes a path to the map, reads first 255 bytes and
 * checks if they are ascii or not. Update bitmask accordingly.
 *
 * @param fd file descriptor of the file to check
 * @param game pointer to the game structure
 * @return int 1 if there is no error, something else otherwise
*/
int	ft_data_sanity(char *path, t_game *game)
{
	int		fd;
	int		i;
	char	buffer[256];

	ft_bzero(buffer, 256);
	fd = open(path, O_RDONLY);
	i = 0;
	if (fd == -1)
		return (game->errors |= ERR_OPEN);
	if (read(fd, buffer, 255) == -1)
		return (game->errors |= ERR_READ);
	close(fd);
	while (buffer[i])
	{
		if (!ft_isascii(buffer[i]))
			return (game->errors |= ERR_CONT);
		i++;
	}
	return (1);
}
