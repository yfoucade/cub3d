/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:18:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 01:21:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include "debug.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game = ft_run_parser(argv[1]);
	// printf("map_buffer: %s\n", game.file_buffer);
	ft_print_game_struct(&game);
	// Mask each errors
	if (game.errors & ERR_OPEN)
		printf("Error : Could not open file '%s'\n", argv[1]);
	if (game.errors & ERR_READ)
		printf("Error : Could not read file '%s'\n", argv[1]);
	if (game.errors & ERR_CONT)
		printf("Error : Unknown file '%s'\n", argv[1]);
	if (game.errors & ERR_NAME)
		printf("Error : File '%s' isn't a .cub file\n", argv[1]);
	if (game.errors & ERR_BUFF)
		printf("Error : Could not allocate memory for file '%s'\n", argv[1]);
	if (game.errors & ERR_MISS_NO)
		printf("Error : Missing NO texture path in file '%s'\n", argv[1]);
	if (game.errors & ERR_MISS_SO)
		printf("Error : Missing SO texture path in file '%s'\n", argv[1]);
	if (game.errors & ERR_MISS_WE)
		printf("Error : Missing WE texture path in file '%s'\n", argv[1]);
	if (game.errors & ERR_MISS_EA)
		printf("Error : Missing EA texture path in file '%s'\n", argv[1]);
	if (game.errors & ERR_INV_F)
		printf("Error : Invalid floor color in file '%s'\n", argv[1]);
	if (game.errors & ERR_INV_C)
		printf("Error : Invalid ceiling color in file '%s'\n", argv[1]);
	if (game.errors == 0)
		printf("No errors found\n");
	else
		printf("Error mask = %lu\n", game.errors);
	ft_destroy_game(&game);
	return (0);
}
