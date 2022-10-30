/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:44:04 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:44:10 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_game(t_game *game)
{
	create_window(game);
	create_frame(game);
	create_hooks(game);
	mlx_loop(game->mlx.mlx_ptr);
	ft_destroy_game(game);
}
