/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:37:44 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/05 15:44:47 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strip(char *s)
{
	ft_lstrip(s);
	ft_rstrip(s);
}

void	ft_lstrip(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (ft_isspace(s[i])))
		i++;
	ft_memmove(s, s + i, ft_strlen(s) - i + 1);
}

void	ft_rstrip(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && (ft_isspace(s[i])))
		i--;
	s[i + 1] = '\0';
}
