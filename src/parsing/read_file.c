/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:00:06 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 02:09:54 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fetch_file_content(char *filename, t_game *game)
{
	int	fd;

	(void)game;
	if (!is_valid_filename(filename))
		error_msg("Invalid file name\n", 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("Could not open file\n", 1);
	if (fetch_loop(fd, game))
	{
		close(fd);
		ft_destroy_game(game);
		exit(1);
	}
	close(fd);
}

char	add_map_line(t_game *game, char *line)
{
	int	i;

	if (lst_add(&game->map_lines, line))
		return (FAILURE);
	game->map_height += 1;
	game->map_width = ft_max_int(game->map_width, ft_strlen(line));
	i = 0;
	while (line[i])
	{
		if (!ft_is_in_charlist(" 10NSEW", line[i++]))
		{
			error_msg("Bad line in map:\n", -1);
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\n", 2);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

char	all_chars_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_is_in_charlist(" 10NSEW", line[i++]))
		{
			ft_putstr_fd("Error\nIllegal character in line: ", 2);
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\n", 2);
			return (FALSE);
		}
	}
	return (TRUE);
}

char	fetch_loop(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (*line == ' ' || *line == '0' || *line == '1')
			break ;
		else if (parse_line(line, game))
			return (free(line), FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (!all_chars_valid(line))
			return (free(line), FAILURE);
		ft_rstrip(line);
		if (add_map_line(game, line))
			return (free(line), FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}
