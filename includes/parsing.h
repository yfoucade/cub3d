/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:57:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/24 22:43:24 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "neo_libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// -- Parsing error bitmask --
# define ERR_OPEN 0b00000000000000000000000000000001
# define ERR_READ 0b00000000000000000000000000000010
# define ERR_CONT 0b00000000000000000000000000000100
# define ERR_NAME 0b00000000000000000000000000001000

// -- Parsing error bitmask --

int				ft_data_sanity(char *path, unsigned long *error_mask);
int				ft_name_sanity(char *filename, unsigned long *errors);
unsigned long	ft_run_parser(char *path);
char			*ft_buffer_map(char *path);

#endif