/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:07:28 by mqwa              #+#    #+#             */
/*   Updated: 2026/05/07 04:06:01 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <limits.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

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

typedef struct s_widths
{
	int	nlink;
	int	user;
	int	group;
	int	size;
}				t_widths;

int		ft_ls(int ac, char **av, t_opt *opt);
int		ft_add_path(t_list **paths, char *str);
int		ft_proceed(t_opt *opt, t_list *paths);
t_list	*ft_sort(t_list *list, t_opt *opt);
int		ft_cmp_time(t_file *a, t_file *b);
int		ft_error_option(char c);
int		ft_print_dir_error(const char *path);
void	ft_print_file_error(t_file *file);
void	ft_process_errors(t_list *paths);
void	ft_free_file(void *content);
int		ft_opendir(const char *path, t_opt *opt);
int		ft_read_dir(DIR *dir, const char *path, t_list **contents, t_opt *opt);
char	*ft_build_full_path(const char *parent, const char *name);
int		ft_is_valid_dir(const char *name);
void	ft_count_types(t_list *paths, int *files, int *dirs, int *errors);
void	ft_display(t_list *files, t_opt *opt, int show_total);
void	ft_print_long(t_file *file, t_widths *w);
void	ft_print_permissions(mode_t mode);
void	ft_print_time(time_t mtime);
void	ft_print_symlink(const char *path);
void	ft_print_owner_group(t_file *file, t_widths *w);
void	ft_calc_widths(t_list *files, t_widths *w);
int		ft_nbrlen(long long n);
int		ft_get_user_len(uid_t uid);
int		ft_get_group_len(gid_t gid);

#endif