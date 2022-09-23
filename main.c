/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:18:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/23 14:54:14 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parsing.h"

int main(int argc, char **argv)
{
	int	fd;
	char *output;

	if (argc != 2)
		return (1);
	if (!ft_name_sanity(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	return (ft_data_sanity(fd, &output) == 0);
}