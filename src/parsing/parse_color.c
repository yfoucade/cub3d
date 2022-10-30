/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:08:55 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 18:15:13 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	ft_set_val(t_color *color, char *s, int index)
{
	int	val;
	int	offset;

	offset = 0;
	ft_strip(s);
	if (!ft_digit_only(s, &offset) || ft_strlen(s + offset) == 0)
		return (0);
	val = ft_atoi(s);
	if (val < 0 || val > 255)
		return (0);
	if (index == 0)
		color->r = ft_atoi(s);
	else if (index == 1)
		color->g = ft_atoi(s);
	else if (index == 2)
		color->b = ft_atoi(s);
	return (1);
}
