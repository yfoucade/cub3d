/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:18:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 23:20:23 by jallerha         ###   ########.fr       */
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

	ret = 0;
	if (argc != 2)
		return (1);
	game = ft_run_parser(argv[1]);
	game.filename = argv[1];
	ft_print_errors(&game);
	if (game.errors != 0)
		ret = 1;
	ft_destroy_game(&game);
	return (ret);
}
