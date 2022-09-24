/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:03:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 01:08:24 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "neo_libft.h"
# include "game.h"

#ifndef DEBUG
# define DEBUG 1
#endif

void	ft_print_game_struct(t_game *game);
void	ft_print_color_struct(t_color *game);
#endif