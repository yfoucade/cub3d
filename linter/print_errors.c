/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:29:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 15:07:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

void	ft_print_errors(t_game *game)
{
	ft_io_errors(game->filename, game->errors);
	ft_invalid_settings_error(game);
	ft_invalid_colors(game);
	ft_invalid_textures(game);
	ft_map_errors(game);
	ft_matrix_errors(game);
}
