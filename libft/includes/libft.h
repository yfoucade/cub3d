/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:29:45 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/03 10:04:35 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include "assert.h"
# include "bool.h"
# include "chartype.h"
# include "colors.h"
# include "constants.h"
# include "conversions.h"
# include "file.h"
# include "get_next_line.h"
# include "lists.h"
# include "math.h"
# include "matrix.h"
# include "memory.h"
# include "neo_libft.h"
# include "printf.h"
# include "put.h"
# include "sort.h"
# include "string.h"

void	ft_putfd(char *str, int fd);
int		ft_strlen(char *str);

#endif