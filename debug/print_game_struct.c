/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:03:44 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 01:12:42 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	ft_print_game_struct(t_game *game)
{
	if (!DEBUG)
		return ;
	ft_printf("Game struct :\n");
	ft_printf("NO_PATH : %s\n", game->no_path);
	ft_printf("SO_PATH : %s\n", game->so_path);
	ft_printf("WE_PATH : %s\n", game->we_path);
	ft_printf("EA_PATH : %s\n", game->ea_path);
	ft_print_color_struct(&game->floor_color);
	ft_print_color_struct(&game->ceiling_color);
	ft_printf("FILE_SIZE: %d\n", ft_strlen(game->file_buffer));
}
