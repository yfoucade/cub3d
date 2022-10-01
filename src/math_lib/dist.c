/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:25:58 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/01 23:10:37 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

double	dist(t_point *a, t_point *b, char free_byte)
{
	return (norm(sub(a, b, free_byte), TRUE));
}
