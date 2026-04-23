/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:07:28 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/23 10:34:47 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

# define EXIT_STATUS 2

typedef struct s_opt
{
	int	opt_l;
	int	opt_r;
	int	opt_rec;
	int	opt_a;
	int	opt_t;
}				t_opt;

typedef struct s_file
{
	char		*path;
	char		*name;
	int			error;
	struct stat	st;
}				t_file;

int		ft_ls(int ac, char **av, t_opt *opt);
int		ft_add_path(t_list **paths, char *str);
t_list	*ft_sort(t_list *list, t_opt *opt);
int		ft_cmp_time(t_file *a, t_file *b);
int		ft_error_option(char c);
void	ft_free_file(void *content);

#endif