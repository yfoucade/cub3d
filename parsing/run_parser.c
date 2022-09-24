/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:05:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 01:20:52 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// TODO : Check parsed colors and apply mask depending of if 'valid' == 1
// TODO : Check if path exists (by trying to opening them, use O_DIRECTORY)

void	ft_check_colors(t_game *game)
{
	if (game->floor_color.valid == 0)
		game->errors |= ERR_INV_F;
	if (game->ceiling_color.valid == 0)
	{
		game->errors |= ERR_INV_C;
	}
}

/**
 * @brief Runs the parser on the given file
 * 
 * @param path Path to the map to parse
 * @return t_game Game structure
 */
t_game	ft_run_parser(char *path)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (ft_data_sanity(path, &game) != 1)
		return (game);
	game.file_buffer = ft_buffer_file(path);
	if (!game.file_buffer)
	{
		game.errors |= ERR_BUFF;
		return (game);
	}
	ft_name_sanity(path, &game);
	ft_parse_textures(&game);
	ft_check_colors(&game);
	return (game);
}
