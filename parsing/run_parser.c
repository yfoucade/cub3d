/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:05:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/24 23:11:59 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Runs the parser on the given file
 * 
 * @param path Path to the map to parse
 * @return unsigned long A bitmask of errors
 */
unsigned long	ft_run_parser(char *path)
{
	unsigned long	errors;

	errors = 0;
	if (ft_data_sanity(path, &errors) != 1)
		return (errors);
	ft_name_sanity(path, &errors);
	return (errors);
}
