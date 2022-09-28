/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:29:38 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 13:05:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lists.h"

void	ft_set_texture(t_game *game, char *s, char **target)
{
	if (*target)
		game->errors |= ERR_DUP_SET;
	else
	{
		ft_strip(s);
		*target = ft_strdup(s);
		game->parsed_settings++;
	}
}

void	ft_set_color(t_game *game, char *s, t_color *target)
{
	if (target->valid == 1)
		game->errors |= ERR_DUP_SET;
	else
	{
		*(target) = ft_parse_rgb(s);
		game->parsed_settings++;
	}
}

void	ft_parse_line(t_game *game, char *s)
{
	if (is_empty(s))
		return ;
	if (ft_strncmp(s, "F ", 2) == 0)
		ft_set_color(game, s + 2, &game->floor_color);
	else if (ft_strncmp(s, "C ", 2) == 0)
		ft_set_color(game, s + 2, &game->ceiling_color);
	else if (ft_strncmp(s, "WE", 2) == 0)
		ft_set_texture(game, s + 3, &game->we_path);
	else if (ft_strncmp(s, "EA", 2) == 0)
		ft_set_texture(game, s + 3, &game->ea_path);
	else if (ft_strncmp(s, "NO", 2) == 0)
		ft_set_texture(game, s + 3, &game->no_path);
	else if (ft_strncmp(s, "SO", 2) == 0)
		ft_set_texture(game, s + 3, &game->so_path);
	else if (game->parsed_settings < 6)
		game->errors |= ERR_INV_ODR;
}

void	ft_parse_settings(t_game *game)
{
	t_chain_lst	*lines;
	t_chain_lst	*tmp;

	lines = ft_split(game->file_buffer, "\n");
	tmp = lines;
	while (tmp)
	{
		ft_parse_line(game, (char *) tmp->content);
		free(tmp->content);
		tmp = tmp->next;
	}
	ft_chain_clear(&lines);
	ft_check_textures(game);
	ft_check_colors(game);
}
