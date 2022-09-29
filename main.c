/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:18:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 16:45:29 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include "debug.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		ret;

	DEBUG_PRINT("To suppress debug output, compile with -DDEBUG=0\n")
	ret = 0;
	if (argc != 2)
		return (1);
	game = ft_run_parser(argv[1]);
	game.filename = argv[1];
	ft_print_errors(&game);
	ft_print_matrix(&game.matrix);
	if (game.errors != 0)
	{
		DEBUG_PRINT("non-zero error mask : %lu\n", game.errors);
		ret = 1;
	}
	else
	{
		ft_start_game(&game);
		ret = 0;
	}
	ft_destroy_game(&game);
	return (ret);
}
