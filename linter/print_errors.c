/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:29:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 23:15:24 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_io_errors(char *filename, unsigned long error_mask)
{
	if (error_mask & ERR_OPEN)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Could not open file%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_READ)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Could not read file%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_CONT)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid map file%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_NAME)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid map name format%s\n",
			RESET, filename, RESET);
	if (error_mask & ERR_BUFF)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Could not allocate memory%s\n",
			RESET, filename, RESET);
}

void	ft_invalid_settings_error(t_game *game)
{
	if (game->errors & ERR_INV_ODR)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid order in map settings%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_NO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing NO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_SO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing SO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_WE)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing WE texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_EA)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing EA texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_F)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing F color%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_MISS_C)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Missing C color%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_DUP_SET)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Duplicate map settings%s\n",
			RESET, game->filename, RESET);
}

void	ft_invalid_colors(t_game *game)
{
	if (game->errors & ERR_INV_C)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid C color%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_F)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid F color%s\n",
			RESET, game->filename, RESET);
}

void	ft_invalid_textures(t_game *game)
{
	if (game->errors & ERR_INV_NO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid NO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_SO)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid SO texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_WE)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid WE texture%s\n",
			RESET, game->filename, RESET);
	if (game->errors & ERR_INV_EA)
		ft_fprintf(STDERR, RED3"fatal: %s'%s' Invalid EA texture%s\n",
			RESET, game->filename, RESET);
}

void	ft_print_errors(t_game *game)
{
	ft_io_errors(game->filename, game->errors);
	ft_invalid_settings_error(game);
	ft_invalid_colors(game);
	ft_invalid_textures(game);
}
