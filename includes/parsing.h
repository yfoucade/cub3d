/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:57:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 16:59:15 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "neo_libft.h"
# include "game.h"
# include "linter.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>

// -- Parsing error bitmask --
# define ERR_OPEN    0x0000000000000001
# define ERR_READ    0x0000000000000002
# define ERR_CONT    0x0000000000000004
# define ERR_NAME    0x0000000000000008
# define ERR_BUFF    0x0000000000000010
# define ERR_MISS_NA 0x0000000000000020
# define ERR_MISS_NO 0x0000000000000040
# define ERR_MISS_SO 0x0000000000000080
# define ERR_MISS_WE 0x0000000000000100
# define ERR_MISS_EA 0x0000000000000200
# define ERR_MISS_F  0x0000000000000400
# define ERR_MISS_C  0x0000000000000800
# define ERR_INV_NO  0x0000000000001000
# define ERR_INV_SO  0x0000000000002000
# define ERR_INV_WE  0x0000000000004000
# define ERR_INV_EA  0x0000000000008000
# define ERR_INV_F   0x0000000000010000
# define ERR_INV_C   0x0000000000020000
# define ERR_INV_ODR 0x0000000000040000
# define ERR_DUP_SET 0x0000000000080000
// -- Parsing error bitmask --

// -- Map sanity error bitmask --
# define ERR_MUL_SPW 0x0000000000100000
# define ERR_NO_SPW  0x0000000000200000
# define ERR_MAP_HOL 0x0000000000400000
# define ERR_MAP_BUF 0x0000000000800000
# define ERR_MAP_MIS 0x0000000001000000
# define ERR_ILL_CHR 0x0000000002000000
# define ERR_MTX_INI 0x0000000004000000
// -- Map sanity error bitmask --

int			ft_data_sanity(char *path, t_game *game);
int			ft_name_sanity(char *filename, t_game *game);
t_game		ft_run_parser(char *path);
char		*ft_buffer_file(char *path);
void		ft_parse_settings(t_game *game);
void		ft_check_textures(t_game *game);
int			is_empty(char *s);
void		ft_buffer_map(t_game *game);
void		ft_check_colors(t_game *game);
void		ft_map_sanity(t_game *game);
void		ft_map_to_matrix(t_game *game);
void		ft_matrix_sanity(t_game *game);
int			ft_is_spawn_char(char c);
t_color		ft_parse_rgb(char *s);
#endif