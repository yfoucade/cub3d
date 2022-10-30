/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:54:24 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:54:31 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_words(char *haystack, char *needle)
{
	int	i;
	int	j;
	int	k;
	int	count;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	while (haystack[i])
	{
		j = 0;
		k = i;
		while (needle[j])
		{
			if (haystack[k] != needle[j])
				break ;
			j++;
			k++;
		}
		if (!needle[j])
			count++;
		i++;
	}
	return (count);
}
