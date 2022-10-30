/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:43:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:43:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_hooks(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, 17, 0, ft_redcross, game);
	mlx_hook(game->mlx.win_ptr, 2, 1, ft_key_press_hook, game);
	mlx_hook(game->mlx.win_ptr, 3, 2, ft_key_release_hook, game);
	mlx_loop_hook(game->mlx.mlx_ptr, ft_game_loop, game);
}
