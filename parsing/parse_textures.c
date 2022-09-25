/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 23:24:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 00:04:47 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_correct_order(char *line, char *order)
{
	if (*order == 6)
		return (ft_strcmp(line, "NO") == 0);
	else if (*order == 5)
		return (ft_strcmp(line, "SO") == 0);
	else if (*order == 4)
		return (ft_strcmp(line, "WE") == 0);
	else if (*order == 3)
		return (ft_strcmp(line, "EA") == 0);
	else if (*order == 2)
		return (ft_strcmp(line, "F ") == 0);
	else if (*order == 1)
		return (ft_strcmp(line, "C ") == 0);
	return (0);
}

/**
 * @brief This functions parse a value (SO, NO, WE, EA, F, C) and store it in
 * the game structure, returns 1 if the value is parsed properly, 0 otherwise.
 * 
 * @param line Current line
 * @param game Pointer to game structure
 * @param order_check Order to check
 * @return char* Parsed value (striped)
 */

int	ft_get_value(char *line, t_game *game, char *order_check)
{
	char	*output;
	char	key[3];

	key[0] = line[0];
	key[1] = line[1];
	key[2] = '\0';
	if (!ft_correct_order(key, order_check))
		return (0);
	output = ft_strdup(line + 2);
	ft_strip(output);
	if (*order_check == 6)
		game->no_path = output;
	else if (*order_check == 5)
		game->so_path = output;
	else if (*order_check == 4)
		game->we_path = output;
	else if (*order_check == 3)
		game->ea_path = output;
	else if (*order_check == 2)
		game->floor_color = ft_parse_rgb(output);
	else if (*order_check == 1)
		game->ceiling_color = ft_parse_rgb(output);
	(*order_check)--;
	return (1);
}

void	ft_parse_textures(t_game *game)
{
	char		order_check;
	char		*line;
	t_chain_lst	*lines;
	t_chain_lst	*tmp;

	order_check = 6;
	lines = ft_split(game->file_buffer, "\n");
	tmp = lines;
	while (tmp)
	{
		line = (char *) tmp->content;
		ft_strip(line);
		if (!is_empty(line))
		{
			if (!ft_get_value(line, game, &order_check))
				game->errors |= ERR_MISS_NA << (6 - order_check);
		}
		free(tmp->content);
		tmp = tmp->next;
	}
	ft_chain_clear(&lines);
}
