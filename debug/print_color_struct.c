/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:07:55 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/25 01:09:07 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	ft_print_color_struct(t_color *color)
{
	if (!DEBUG)
		return ;
	ft_printf("Color struct :\n");
	ft_printf("r = %d\n", color->r);
	ft_printf("g = %d\n", color->g);
	ft_printf("b = %d\n", color->b);
	ft_printf("valid = %d\n", color->valid);
}
