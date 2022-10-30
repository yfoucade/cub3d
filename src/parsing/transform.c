/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:57:08 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	transform_map(t_game *game)
{
	if (init_empty_map(game))
		return (FAILURE);
	fill_map(game);
	return (SUCCESS);
}
