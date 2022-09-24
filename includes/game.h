/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 23:42:54 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 01:04:32 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

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
	unsigned long	errors;
	t_color			floor_color;
	t_color			ceiling_color;
}	t_game;

void	ft_destroy_game(t_game *game);
t_color	ft_parse_rgb(char *s);

#endif