/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:09:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 22:11:31 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game.h"

void	ft_destroy_game(t_game *game)
{
	free(game->ea_path);
	free(game->so_path);
	free(game->we_path);
	free(game->no_path);
	free(game->file_buffer);
}
