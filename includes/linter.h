/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:29:26 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 15:07:29 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINTER_H
# define LINTER_H

# include "parsing.h"
# include "colors.h"
# include "printf.h"

void	ft_io_errors(char *filename, unsigned long error_mask);
void	ft_print_errors(t_game *game);
void	ft_invalid_colors(t_game *game);
void	ft_invalid_settings_error(t_game *game);
void	ft_invalid_textures(t_game *game);
void	ft_map_errors(t_game *game);
void	ft_matrix_errors(t_game *game);

#endif