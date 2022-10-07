/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:00:49 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/06 04:41:08 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_game(t_game *game)
{
	print_array(game->map);
	printf("player starting pos: %f, %f\n", game->player_pos->x, game->player_pos->y);
}

void	print_array(char **array)
{
	char	**tmp;

	tmp = array;
	while (*tmp)
		printf("%s\n", *tmp++);
}
