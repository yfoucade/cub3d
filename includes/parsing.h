/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:57:37 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/23 14:54:25 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "neo_libft.h"

int	ft_data_sanity(int fd, char **output);
int	ft_name_sanity(char *filename);

#endif