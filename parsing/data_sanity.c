/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sanity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:50:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/23 14:47:55 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file checks a function that check whether the file contains non-ascii
// data or not, this is used to abort parsing before the parser tries to
// allocate a huge amount of memory for a file that is not a valid map.
// (such as /dev/(u)random or any other kind)

// in order to collect a safe-sample, we will only read two lines in the file
// and check if they are ascii or not.

#include "parsing.h"

/**
 * @brief This function reads first two lines of a file and check if they are
 * ascii or not.
 * 
 * @param fd file descriptor of the file to check
 * @param output pointer to a variable that will contains the entire map
 * @return int 1 if the file is ascii, 0 otherwise
*/
int	ft_data_sanity(int fd, char **output)
{
	char	*line1;
	char	*line2;
	int		i;
	int		sanity_flag;

	i = 0;
	sanity_flag = 1;
	line1 = get_next_line(fd);
	line2 = get_next_line(fd);
	if (line1 == NULL || line2 == NULL)
		sanity_flag = 0;
	while (line1[i] && sanity_flag)
	{
		if (!ft_isascii(line1[i]))
			sanity_flag = 0;
		i++;
	}
	i = 0;
	while (line2[i] && sanity_flag)
	{
		if (!ft_isascii(line2[i]))
			sanity_flag = 0;
		i++;
	}
	if (sanity_flag)
	{
		*output = ft_strsjoin(line1, line2);
		*output = ft_strsjoin(*output, get_next_line(fd));
	}
	else
	{
		free(line1);
		free(line2);
	}
	return (sanity_flag);
}