/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:42:34 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/03 22:48:06 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_endswith(char *str, char *end)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = ft_strlen(end);
	if (!j)
		return (TRUE);
	if (i < j)
		return (FALSE);
	while (--i, --j)
		if (str[i] != end[j])
			return (FALSE);
	return (str[i] == end[j]);
}