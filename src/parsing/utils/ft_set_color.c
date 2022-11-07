/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:55:02 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 01:29:56 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	ft_set_color(char *s, t_color **target)
{
	if (*target)
		return (error_msg("Error\nColor is set multiple times\n", -1));
	else
	{
		*target = ft_parse_rgb(s);
		if (!*target)
			return (FAILURE);
	}
	return (SUCCESS);
}
