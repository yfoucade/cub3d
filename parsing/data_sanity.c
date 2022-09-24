/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sanity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:50:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/24 23:11:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file checks a function that check whether the file contains non-ascii
// data or not, this is used to abort parsing before the parser tries to
// allocate a huge amount of memory for a file that is not a valid map.
// (such as /dev/(u)random or any other kind)

// in order to collect a safe-sample, we will only read 256 bytes in the file
// and check if they are ascii or not.

#include "parsing.h"

/**
 * @brief This function takes a path to the map, reads first 256 bytes and
 * checks if they are ascii or not. Update bitmask accordingly.
 *
 * @param fd file descriptor of the file to check
 * @param error_mask pointer to error mask
 * @return int 1 if there is no error, something else otherwise
*/
int	ft_data_sanity(char *path, unsigned long *error_mask)
{
	int		fd;
	int		i;
	char	buffer[256];

	fd = open(path, O_RDONLY);
	i = 0;
	if (fd == -1)
		return (*error_mask |= ERR_OPEN);
	if (read(fd, buffer, 256) == -1)
		return (*error_mask |= ERR_READ);
	close(fd);
	while (buffer[i])
	{
		if (!ft_isascii(buffer[i]))
			return (*error_mask |= ERR_CONT);
		i++;
	}
	return (1);
}
