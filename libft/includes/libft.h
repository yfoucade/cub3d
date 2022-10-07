/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:12:32 by yfoucade          #+#    #+#             */
/*   Updated: 2022/10/05 20:42:01 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE 1

typedef struct s_str_list
{
	char				*str;
	struct s_str_list	*next;
}	t_str_list;

void	free_array(char **array);
void	free_str_list(t_str_list *str_list);
int		ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);
char	ft_endswith(char *str, char *end);
char	ft_is_in_charlist(char *lst, char c);
int		ft_isblank(int c);
char	ft_isdigit(char c);
int		ft_isspace(int c);
int		ft_max_int(int a, int b);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(char *str, int fd);
char	ft_startswith(char *str, char *start);
char	*ft_strcat(char *s1, char *s2);
void	ft_strip(char *s);
void	ft_lstrip(char *s);
void	ft_rstrip(char *s);
int		ft_strlen(char *str);
char	*ft_strndup(char *str, int n);
char	lst_add_n(t_str_list **lst, char *str, char *end);
char	lst_add(t_str_list **lst, char *str);

#endif
