/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_sanity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:52:54 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/23 15:02:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cub3d files must start with whatever, and end in .cub
// todo : insensitive to case check ?

#include "parsing.h"

int	ft_name_sanity(char *filename)
{
	return (ft_endswith(filename, ".cub"));
}