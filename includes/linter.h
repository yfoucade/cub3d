/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:29:26 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/26 23:15:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINTER_H
# define LINTER_H

# include "parsing.h"
# include "colors.h"
# include "printf.h"

void	ft_io_errors(char *filename, unsigned long error_mask);
void	ft_print_errors(t_game *game);

#endif