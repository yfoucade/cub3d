/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:49:42 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/07 21:16:19 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	is_valid_filename(char *name)
{
	if (!ft_endswith(name, ".cub"))
		return (FALSE);
	return (TRUE);
}

char	is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != '\n' && !ft_isblank(*line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

char	add_texture(char *path, t_game *game, void **texture_holder)
{
	int	ignore;

	ft_strip(path);
	*texture_holder = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path, &ignore, &ignore);
	if (!*texture_holder)
	{
		ft_putstr_fd("Error\nCould not load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_count_words(char *haystack, char *needle)
{
	int	i;
	int	j;
	int	k;
	int	count;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	while (haystack[i])
	{
		j = 0;
		k = i;
		while (needle[j])
		{
			if (haystack[k] != needle[j])
				break ;
			j++;
			k++;
		}
		if (!needle[j])
			count++;
		i++;
	}
	return (count);
}

t_str_list	*ft_split(char *str, char c)
{
	t_str_list	*res;
	char		*end;

	if (!str)
		return (NULL);
	res = NULL;
	while (*str)
	{
		end = str;
		while (*end && *end != c)
			++end;
		if (lst_add_n(&res, str, end))
		{
			free_str_list(res);
			return (NULL);
		}
		str = end + (*end == c);
	}
	return (res);
}

int	ft_digit_only(char *s, int *offset)
{
	int	i;

	i = 0;
	if (s[i] == '+')
		i++;
	*offset = i;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char	ft_set_val(t_color *color, char *s, int index)
{
	int	val;
	int	offset;

	offset = 0;
	ft_strip(s);
	if (!ft_digit_only(s, &offset) || ft_strlen(s + offset) == 0)
		return (0);
	val = ft_atoi(s);
	if (val < 0 || val > 255)
		return (0);
	if (index == 0)
		color->r = ft_atoi(s);
	else if (index == 1)
		color->g = ft_atoi(s);
	else if (index == 2)
		color->b = ft_atoi(s);
	return (1);
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

t_color	*ft_parse_rgb(char *s)
{
	t_color		*res;
	t_str_list	*lst;

	lst = ft_split(s, ',');
	if (!lst)
		return (NULL);
	res = malloc(sizeof(*res));
	if (!res)
		return (free_str_list(lst), NULL);
	if (ft_parse(lst, res))
		return (free_str_list(lst), free(res), NULL);
	free_str_list(lst);
	res->color_hex = (res->r << 16) | (res->g << 8) | res->b;
	return (res);
}

char	ft_set_color(char *s, t_color **target)
{
	if (*target)
		return (error_msg("Color is set multiple times\n", -1));
	else
	{
		*target = ft_parse_rgb(s);
		if (!*target)
			return (FAILURE);
	}
	return (SUCCESS);
}

char	parse_line(char *line, t_game *game)
{
	if (is_empty_line(line))
		return (SUCCESS);
	else if (ft_startswith(line, "NO "))
		return (add_texture(line + 3, game, &game->mlx.no_img));
	else if (ft_startswith(line, "SO "))
		return (add_texture(line + 3, game, &game->mlx.so_img));
	else if (ft_startswith(line, "WE "))
		return (add_texture(line + 3, game, &game->mlx.we_img));
	else if (ft_startswith(line, "EA "))
		return (add_texture(line + 3, game, &game->mlx.ea_img));
	else if (ft_startswith(line, "F "))
		return (ft_set_color(line + 2, &game->floor_color));
	else if (ft_startswith(line, "C "))
		return (ft_set_color(line + 2, &game->ceiling_color));
	ft_putstr_fd("Error\nInvalid line: ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	return (FAILURE);
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
		ft_rstrip(line);
		if (add_map_line(game, line))
			return (free(line), FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}

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

void	init_mlx_ptr(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		error_msg("Failed to initialize mlx\n", 1);
}

char	init_empty_map(t_game *game)
{
	int	i;

	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (FAILURE);
	ft_bzero(game->map, sizeof(char *) * (game->map_height + 1));
	i = -1;
	while (++i < game->map_height)
	{
		game->map[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[i])
			return (free_array(game->map), FAILURE);
		ft_memset(game->map[i], ' ', game->map_width);
		game->map[i][game->map_width] = '\0';
	}
	return (SUCCESS);
}

void	fill_map(t_game *game)
{
	char		**tmp_array;
	t_str_list	*tmp_lst;

	tmp_array = game->map;
	tmp_lst = game->map_lines;
	while (tmp_lst)
	{
		ft_memmove(*tmp_array, tmp_lst->str, ft_strlen(tmp_lst->str));
		++tmp_array;
		tmp_lst = tmp_lst->next;
	}
}

char	rectangularize_map(t_game *game)
{
	if (init_empty_map(game))
		return (FAILURE);
	fill_map(game);
	return (SUCCESS);
}

char	is_valid_transition(char old, char new)
{
	if (old == ' ')
		return (ft_is_in_charlist(" 1", new) || new  == '\0');
	if (old == '0')
		return (ft_is_in_charlist("01NEWS", new));
	if (old == '1')
		return (TRUE);
	return (new == '0' || new == '1');
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

char	map_is_closed(t_game *game)
{
	int	start_row;
	int	start_col;

	start_row = -1;
	start_col = 0;
	while (++start_row < game->map_height)
		if (check_line(game, start_row, start_col, 0, 1))
			return (FALSE);
	start_row = 0;
	start_col = -1;
	while (++start_col < game->map_width)
		if (check_line(game, start_row, start_col, 1, 0))
			return (FALSE);
	return (TRUE);
}

char	textures_set(t_game *game)
{
	if (!game->mlx.no_img)
		return (FALSE);
	if (!game->mlx.so_img)
		return (FALSE);
	if (!game->mlx.ea_img)
		return (FALSE);
	if (!game->mlx.we_img)
		return (FALSE);
	if (!game->floor_color)
		return (FALSE);
	if (!game->ceiling_color)
		return (FALSE);
	return (TRUE);
}

char	set_pos_dir_plane(t_game *game, int row, int col)
{
	if (game->player_pos.x)
		return (FAILURE); // multiple starting positions.
	game->player_pos = create(col * (GST_TILE_SIZE) + .5, row * (GST_TILE_SIZE) + .5);
	if (game->map[row][col] == 'N')
		game->player_dir = create(0, -1);
	if (game->map[row][col] == 'E')
		game->player_dir = create(1, 0);
	if (game->map[row][col] == 'W')
		game->player_dir = create(-1, 0);
	if (game->map[row][col] == 'S')
		game->player_dir = create(0, 1);
	update_plane(game);
	return (SUCCESS);
}

char	init_game_data(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->map_height)
	{
		col = -1;
		while (++col < game->map_width)
		{
			if (ft_is_in_charlist("NEWS", game->map[row][col]))
			{
				if (set_pos_dir_plane(game, row, col))
					return (FAILURE);
			}
		}
	}
	return (SUCCESS);
}

void	parse(int ac, char **av, t_game *game)
{
	if (ac != 2)
		error_msg("Usage: cub3d map\n", 1);
	ft_bzero(game, sizeof(*game));
	init_mlx_ptr(game);
	fetch_file_content(av[1], game);
	if (!textures_set(game) || rectangularize_map(game))
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
