/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:29:54 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 14:30:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_io_errors(char *filename, unsigned long error_mask)
{
	if (error_mask & ERR_OPEN)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Could not open file%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_READ)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Could not read file%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_CONT)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid map file%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_NAME)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid map name format%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_BUFF)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Could not allocate memory%s\n",
			RESET, filename, RESET);
}
