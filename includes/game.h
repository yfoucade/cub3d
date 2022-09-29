/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 23:42:54 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 14:39:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "lists.h"
# include "matrix.h"

# define WALL 1
# define EMPTY 0
# define PLAYER_NORTH 2
# define PLAYER_SOUTH 3
# define PLAYER_EAST 4
# define PLAYER_WEST 5
# define VOID 9

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	valid;
}	t_color;

typedef struct s_game
{
	char			*file_buffer;
	char			*map_buffer;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*filename;
	short			parsed_settings;
	int				map_size;
	unsigned long	errors;
	t_color			floor_color;
	t_color			ceiling_color;
	t_chain_lst		*map_lines;
	t_matrix		matrix;
}	t_game;

void	ft_destroy_game(t_game *game);
t_color	ft_parse_rgb(char *s);

#endif