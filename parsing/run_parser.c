/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:05:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 15:00:35 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// TODO : Check if path exists (by trying to opening them, use O_DIRECTORY)

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
	game.map_size = ft_strlen(game.file_buffer);
	if (!game.file_buffer)
	{
		game.errors |= ERR_BUFF;
		return (game);
	}
	ft_name_sanity(path, &game);
	ft_parse_settings(&game);
	ft_buffer_map(&game);
	ft_map_sanity(&game);
	ft_map_to_matrix(&game);
	if (game.matrix.rows > 0)
		ft_matrix_sanity(&game);
	return (game);
}
