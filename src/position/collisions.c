/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:42:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:42:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	is_in_wall(t_game *game, t_point pos)
{
	if (game->map[(int)pos.y][(int)pos.x] == '1')
		return (TRUE);
	return (FALSE);
}
