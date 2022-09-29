/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:03:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 16:14:32 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "neo_libft.h"
# include "game.h"
# include <stdio.h>

# ifndef DEBUG
#  define DEBUG 1
# endif

# define DEBUG_PRINT(...) if (DEBUG) { printf("[%s:%d] ", __FILE__, __LINE__); printf(__VA_ARGS__); }

void	ft_print_game_struct(t_game *game);
void	ft_print_color_struct(t_color *game);
void	ft_print_matrix(t_matrix *matrix);
#endif