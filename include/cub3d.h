/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:49:36 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/02 18:36:38 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "math_lib.h"
# include "libft.h"

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE 1

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	valid;
	int	color_hex;
}	t_color;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
}	t_mlx;

typedef struct s_game
{
	char				*file_buffer;
	char				*map_buffer;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*filename;
	short				parsed_settings;
	int					map_size;
	float				player_x;
	float				player_y;
	unsigned long long	errors;
	t_color				floor_color;
	t_color				ceiling_color;
	t_chain_lst			*map_lines;
	t_matrix			matrix;
	t_mlx				mlx;
}	t_game;

int	error_msg(char *msg);

#endif