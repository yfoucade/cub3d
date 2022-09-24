/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:05:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/24 23:21:12 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	if (ft_data_sanity(path, &game.errors) != 1)
		return (game);
	game.file_buffer = ft_buffer_map(path);
	if (!game.file_buffer)
	{
		game.errors |= ERR_BUFF;
		return (game)
	}
	ft_name_sanity(path, &game.errors);
	return (game);
}
