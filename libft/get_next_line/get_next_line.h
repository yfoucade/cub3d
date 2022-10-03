/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:32:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/23 13:43:39 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef EOL
#  define EOL -2
# endif

# ifndef READING
#  define READING 1
# endif

# ifndef ERROR
#  define ERROR -1
# endif

char	*get_next_line(int fd);

typedef struct s_file_buffer
{
	char	buf[BUFFER_SIZE + 1];
	int		current_index;
}	t_file_buffer;

#endif