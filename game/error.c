/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:02:05 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 17:04:22 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "printf.h"
#include "constants.h"
#include "colors.h"

void	ft_print_error(t_game *game, char *message, int exit)
{
	ft_fprintf(STDERR, RED3"error: %s%s\n", RESET, message);
	if (exit)
		ft_destroy_game(game);
}