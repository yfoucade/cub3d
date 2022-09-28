/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:38:59 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 14:10:46 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "file.h"

// TODO: This file is dirty, refactor it

char	*ft_init(char **output, char **tmp, int *map_size)
{
	*map_size = 0;
	*output = malloc(1);
	*output[0] = '\0';
	*tmp = NULL;
	return (*output);
}

char	*ft_free_locals(char *line, char *tmp, char *output)
{
	free(line);
	free(tmp);
	free(output);
	return (NULL);
}

/**
 * @brief This function will buffer the entire file to memory
 * This function returns NULL if there is any kind of error
 * @param path Path to the file to buffer
 * @return char* Pointer to the buffer
*/
char	*ft_buffer_file(char *path)
{
	return (ft_read_file(path));
}
