/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:38:59 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 23:19:49 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	char	*output;
	char	*tmp;
	char	*line;
	int		fd;
	int		map_size;

	ft_init(&output, &tmp, &map_size);
	if (!output)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map_size += ft_strlen(line);
		tmp = ft_strsjoin(output, line);
		if (!tmp)
			return (ft_free_locals(line, tmp, output));
		ft_free_locals(line, NULL, output);
		output = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (output);
}
