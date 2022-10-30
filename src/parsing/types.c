/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:51:47 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:59:31 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != '\n' && !ft_isblank(*line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

int	ft_digit_only(char *s, int *offset)
{
	int	i;

	i = 0;
	if (s[i] == '+')
		i++;
	*offset = i;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
