/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:57:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/24 23:36:51 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "neo_libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>

// -- Parsing error bitmask --
# define ERR_OPEN	 0b00000000000000000000000000000001
# define ERR_READ	 0b00000000000000000000000000000010
# define ERR_CONT	 0b00000000000000000000000000000100
# define ERR_NAME	 0b00000000000000000000000000001000
# define ERR_BUFF	 0b00000000000000000000000000010000
# define ERR_MISS_NO 0b00000000000000000000000000100000
# define ERR_MISS_SO 0b00000000000000000000000001000000
# define ERR_MISS_WE 0b00000000000000000000000010000000
# define ERR_MISS_EA 0b00000000000000000000000100000000
# define ERR_MISS_F	 0b00000000000000000000001000000000
# define ERR_MISS_C	 0b00000000000000000000010000000000
# define ERR_INV_NO  0b00000000000000000000100000000000
# define ERR_INV_SO  0b00000000000000000001000000000000
# define ERR_INV_WE  0b00000000000000000010000000000000
# define ERR_INV_EA  0b00000000000000000100000000000000
# define ERR_INV_F	 0b00000000000000001000000000000000
# define ERR_INV_C	 0b00000000000000010000000000000000
// -- Parsing error bitmask --

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	hex;
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

int		ft_data_sanity(char *path, t_game *game);
int		ft_name_sanity(char *filename, t_game *game);
t_game	ft_run_parser(char *path);
char	*ft_buffer_file(char *path);

#endif