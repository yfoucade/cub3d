/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:38:59 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 16:07:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "file.h"

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
