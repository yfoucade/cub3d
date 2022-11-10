/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:49:36 by yfoucade          #+#    #+#             */
/*   Updated: 2022/11/10 09:11:18 by yfoucade         ###   ########.fr       */
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

# define XK_LEFT 0xff51
# define XK_RIGHT 0xff53
# define XK_ESCAPE 0xff1b

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE 1

# define KEY_ON 1
# define KEY_OFF 0

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

# define WIN_WIDTH 800
# define WIN_HEIGHT 450

// Game settings
# define GST_TILE_SIZE 1
# define GST_MOVE_SPEED .030
# define GST_ROT_SPEED .018
# define GST_DIR_SIZE 1
# define GST_PLANE_SIZE 1
# define GST_WALL_HEIGHT 50

# define EPS .02

# ifndef DEBUG
#  define DEBUG 1
# endif

typedef struct s_file_buffer
{
	char	buf[BUFFER_SIZE + 1];
	int		current_index;
}	t_file_buffer;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color_hex;
}	t_color;

typedef struct s_keys
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	left;
	char	right;
}	t_keys;

typedef struct s_img
{
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		curr_frame;
	t_img		no_img;
	t_img		so_img;
	t_img		we_img;
	t_img		ea_img;
}	t_mlx;

typedef struct s_rtvars
{
	int		screen_x;
	double	camera_x;
	t_point	ray;
	int		map_x;
	int		map_y;
	t_point	side_dist;
	t_point	delta_dist;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		draw_start;
	int		draw_end;
	int		line_height;
	t_img	texture;
	int		tex_x;
	int		tex_y;
}	t_rtvars;

typedef struct s_game
{
	int			map_width;
	int			map_height;
	char		init_frame;
	t_point		player_pos;
	t_point		player_dir;
	t_point		camera_plane;
	t_rtvars	rt_vars;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_str_list	*map_lines;
	char		**map;
	t_mlx		mlx;
	t_keys		pressed_keys;
}	t_game;

int			error_msg(char *msg, int exit_value);

// bounds.c
void		rc_calc_bounds(t_game *game);

// cub3d.c
void		draw_walls(t_game *game);

// dda.c
void		rc_run_dda(t_game *game);

// destroy.c
void		ft_destroy_mlx(t_game *game);
void		ft_destroy_game(t_game *game);

//distance.c
void		rc_distance(t_game *game);

// draw.c
void		ft_put_pixel(t_game *game, int row, int col, int hex);
int			ft_get_pixel(t_img	img, int row, int col);
void		create_frame(t_game *game);

// exit.c
int			ft_redcross(t_game *game);

// get_next_line.c
char		*get_next_line(int fd);

// hooks/init.c
void		create_hooks(t_game *game);

// init.c
void		create_window(t_game *game);
char		init_game_data(t_game *game);

// key.c
char		key_pressed(t_game *game);
int			ft_key_release_hook(int keycode, t_game *game);
int			ft_key_press_hook(int keycode, t_game *game);

// loop.c
int			ft_game_loop(t_game *game);

// parsing/map_data.c
t_img		get_texture(t_game *game);
char		set_pos_dir_plane(t_game *game, int row, int col);
char		textures_set(t_game *game);
char		add_texture(char *path, t_game *game, t_img *img);
void		fill_map(t_game *game);

// parsing/parse.c
void		parse(int ac, char **av, t_game *game);
char		is_valid_transition(char old, char new_);
char		check_line(t_game *game, int row, int col, char d_row);
char		ft_parse(t_str_list *lst, t_color *color);

// parsing/parse_color.c
char		ft_set_val(t_color *color, char *s, int index);

// parsing/parse_line.c
char		ft_set_color(char *s, t_color **target);
char		parse_line(char *line, t_game *game);

// parsing/read_file.c
void		fetch_file_content(char *filename, t_game *game);
char		fetch_loop(int fd, t_game *game);

// parsing/sanity.c
char		map_is_closed(t_game *game);
char		is_valid_filename(char *name);

// parsing/transform.c
char		transform_map(t_game *game);

// parsing/types.c
int			ft_digit_only(char *s, int *offset);
char		is_empty_line(char *line);

// parsing/utils/ft_parse_rgb.c
t_color		*ft_parse_rgb(char *s);

// parsing/utils/ft_split.c
t_str_list	*ft_split(char *str, char c);

// parsing/utils/init.c
void		init_mlx_ptr(t_game *game);
char		init_empty_map(t_game *game);

// position/collisions.c
void		handle_collisions(t_game *game, t_point *mov);

// render.c
void		draw_frame(t_game *game);

// run.c
void		run_game(t_game *game);

// update.c
void		update_pos_dir_plane(t_game	*game);
void		update_plane(t_game *game);

// vars.c
void		rc_set_vars(t_game *game);

// wall_collision.c
double		rc_wall_collision(t_game *game);

// print_utils.c
void		print_point(char *s1, t_point a, char *s2);
void		print_game(t_game *game);
void		print_array(char **array);

#endif