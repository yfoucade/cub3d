/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:57:44 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 17:57:58 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	parse_line(char *line, t_game *game)
{
	if (is_empty_line(line))
		return (SUCCESS);
	else if (ft_startswith(line, "NO "))
		return (add_texture(line + 3, game, &game->mlx.no_img));
	else if (ft_startswith(line, "SO "))
		return (add_texture(line + 3, game, &game->mlx.so_img));
	else if (ft_startswith(line, "WE "))
		return (add_texture(line + 3, game, &game->mlx.we_img));
	else if (ft_startswith(line, "EA "))
		return (add_texture(line + 3, game, &game->mlx.ea_img));
	else if (ft_startswith(line, "F "))
		return (ft_set_color(line + 2, &game->floor_color));
	else if (ft_startswith(line, "C "))
		return (ft_set_color(line + 2, &game->ceiling_color));
	ft_putstr_fd("Error\nInvalid line: ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	return (FAILURE);
}
