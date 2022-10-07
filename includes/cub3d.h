/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:49:36 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/07 11:49:30 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "math_lib.h"
# include "libft.h"
# include "mlx.h"

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef EOL
#  define EOL -2
# endif

# ifndef ERROR
#  define ERROR -1
# endif

# ifndef READING
#  define READING 1
# endif

# define GST_TILE_SIZE 1
# define GST_MOVE_SPEED .1
# define GST_ROT_SPEED 1
# define GST_DIR_SIZE .1
# define GST_PLANE_SIZE .1

# ifndef DEBUG
#  define DEBUG 1
# endif

# define DEBUG_PRINT(...) if (DEBUG) { printf("[%s:%d] ", __FILE__, __LINE__); printf(__VA_ARGS__); }

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
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
	int			map_width;
	int			map_height;
	t_point		*player_pos;
	t_point		*player_dir;
	t_point		*camera_plane;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_str_list	*map_lines;
	char		**map;
	// t_matrix	matrix;
	t_mlx		mlx;
}	t_game;

int		error_msg(char *msg, int exit_value);

// cub3d.c
void	run_game(t_game *game);

// destroy.c
void	ft_destroy_mlx(t_game *game);
void	ft_destroy_game(t_game *game);

// get_next_line.c
char	*get_next_line(int fd);

// parser.c
void	parse(int ac, char **av, t_game *game);

//print_utils.c
void	print_game(t_game *game);
void	print_array(char **array);

#endif