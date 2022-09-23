/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:51:02 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/23 15:05:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINTER_H
# define LINTER_H

#include "neo_libft.h"

# define ERR_INFO 0
# define ERR_WARNING 1
# define ERR_ERROR 2

/* Name error */
# define ERR_NAME_TYPE 2
# define ERR_NAME_DESC "Map name must end with '.cub'"

/* Data integrity error */
# define ERR_DATA_INTEGRITY_TYPE 2
# define ERR_DATA_INTEGRITY_DESC "Non-ascii data was found in the map"

typedef struct s_error
{
	char	*file;
	char	*desc;
	int		line;
	int		error_type;
}				t_error;

t_chain_lst	*ft_push_error(char *filename, char *error_desc, int line, int type);

#endif