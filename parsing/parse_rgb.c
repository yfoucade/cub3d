/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:57:10 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 13:18:00 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "neo_libft.h"
#include <stdio.h>

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

/**
 * @brief Writes to a color structure the rgb values from a string
 * 
 * @param color Pointer to color structure to write to
 * @param s String containing the R G B values (ex: "1" or "12" or "123")
 * @param index Index of the color to write to (0 = R, 1 = G, 2 = B)
 * @return int Returns 1 if the value is parsed properly, 0 otherwise
*/
int	ft_set_val(t_color *color, char *s, int index)
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

/**
 * @brief Parse any r,g,b value and store it in a color struct.
 * Valid formats :
 * 1. 255,255,255
 * 2. 255, 255, 255
 * 3. 255,                        255, 255
 * etc
 * @param s String to parse
 * @return t_color Parsed color
*/
t_color	ft_parse_rgb(char *s)
{
	char		*val;
	int			i;
	t_color		output;
	t_chain_lst	*lst;
	t_chain_lst	*tmp;

	i = 0;
	ft_bzero(&output, sizeof(t_color));
	if (ft_count_words(s, ",") != 2)
		return (output);
	lst = ft_split(s, ",");
	tmp = lst;
	while (tmp)
	{
		val = (char *) tmp->content;
		if (!ft_set_val(&output, val, i))
			return (output);
		i++;
		free(tmp->content);
		tmp = tmp->next;
	}
	ft_chain_clear(&lst);
	output.valid = 1;
	free(s);
	return (output);
}
