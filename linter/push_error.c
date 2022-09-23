/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:57:45 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/23 15:03:55 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linter.h"

t_error	ft_create_error(char *filename, char *error_desc, int line, int type)
{
	t_error error;

	error.file = filename;
	error.desc = error_desc;
	error.line = line;
	error.error_type = type;
	return (error);
}

t_chain_lst	*ft_push_error(char *filename, char *error_desc, int line, int type)
{
	static t_chain_lst *error_list = NULL;
	t_error	error;

	error = ft_create_error(filename, error_desc, line, type);
	if (!error_list)
		error_list = ft_chain_new(&error);
	else
		ft_chain_append(&error_list, &error);
	return (error_list);
}