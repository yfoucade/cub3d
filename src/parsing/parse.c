/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:01:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/30 18:12:38 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(int ac, char **av, t_game *game)
{
	if (ac != 2)
		error_msg("Usage: cub3d map\n", 1);
	ft_bzero(game, sizeof(*game));
	init_mlx_ptr(game);
	fetch_file_content(av[1], game);
	if (!textures_set(game) || transform_map(game))
	{
		ft_destroy_game(game);
		exit(1);
	}
	if (!map_is_closed(game) || init_game_data(game))
	{
		ft_destroy_game(game);
		exit(1);
	}
	game->init_frame = TRUE;
	print_game(game);
}

char	ft_parse(t_str_list *lst, t_color *color)
{
	t_str_list	*tmp;
	char		*val;
	int			i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		val = (char *) tmp->str;
		if (!ft_set_val(color, val, i))
			return (FAILURE);
		tmp = tmp->next;
		i++;
	}
	return (SUCCESS);
}

char	check_line(t_game *game, int row, int col, char d_row, char d_col)
{
	char	prev_state;

	prev_state = game->map[row][col];
	if (prev_state != ' ' && prev_state != '1')
	{
		ft_putstr_fd("Illegal char in line: ", 2);
		write(2, game->map[row], game->map_width);
		ft_putstr_fd("\n", 2);
		return (FAILURE);
	}
	while (row < game->map_height && col < game->map_width)
	{
		if (!is_valid_transition(prev_state, game->map[row][col]))
		{
			ft_putstr_fd("check_line: invalid row\n", 2);
			ft_putstr_fd(game->map[row], 2);
			return (FAILURE);
		}
		prev_state = game->map[row][col];
		row += d_row;
		col += d_col;
	}
	if (ft_is_in_charlist(" 1", game->map[row - d_row][col - d_col]))
		return (SUCCESS);
	return (FAILURE);
}
