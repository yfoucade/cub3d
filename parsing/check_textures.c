/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:23:14 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 14:07:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Check that the file passed to the parser is a readable, .xpm file
 * 
 * @param texture_path Path to the texture file
 * @return int Returns 1 if the file is valid, 0 otherwise
 */
int	ft_check_texture(char *texture_path)
{
	int		fd;
	char	buffer[1];

	if (!ft_endswith(texture_path, ".xpm"))
		return (0);
	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (read(fd, buffer, 1) == -1)
		return (0);
	close(fd);
	return (1);
}

/**
 * @brief Check all textures parsed in the game struct
 * and writes to error mask accordingly
 * @param game Pointer to game structure
 */
void	ft_check_textures(t_game *game)
{
	if (!game->no_path || !ft_check_texture(game->no_path))
		game->errors |= ERR_INV_NO;
	if (!game->so_path || !ft_check_texture(game->so_path))
		game->errors |= ERR_INV_SO;
	if (!game->we_path || !ft_check_texture(game->we_path))
		game->errors |= ERR_INV_WE;
	if (!game->ea_path || !ft_check_texture(game->ea_path))
		game->errors |= ERR_INV_EA;
}
