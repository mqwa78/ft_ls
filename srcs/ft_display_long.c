/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 00:14:30 by mqwa              #+#    #+#             */
/*   Updated: 2026/05/07 04:18:09 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_long(t_file *file, t_widths *w)
{
	ft_print_permissions(file->st.st_mode);
	ft_putnchar_fd(' ', w->nlink - ft_nbrlen(file->st.st_nlink), 1);
	ft_putnbr(file->st.st_nlink);
	ft_putchar(' ');
	ft_print_owner_group(file, w);
	ft_putnchar_fd(' ', w->size - ft_nbrlen(file->st.st_size), 1);
	ft_putlld(file->st.st_size);
	ft_putchar(' ');
	ft_print_time(file->st.st_mtime);
	ft_printf(" %s", file->name);
	if (S_ISLNK(file->st.st_mode))
		ft_print_symlink(file->path);
	ft_printf("\n");
}

static void	ft_print_perm_char(mode_t mode, mode_t mask, char c)
{
	if (mode & mask)
		ft_putchar(c);
	else
		ft_putchar('-');
}

void	ft_print_permissions(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else
		ft_putchar('-');
	ft_print_perm_char(mode, S_IRUSR, 'r');
	ft_print_perm_char(mode, S_IWUSR, 'w');
	ft_print_perm_char(mode, S_IXUSR, 'x');
	ft_print_perm_char(mode, S_IRGRP, 'r');
	ft_print_perm_char(mode, S_IWGRP, 'w');
	ft_print_perm_char(mode, S_IXGRP, 'x');
	ft_print_perm_char(mode, S_IROTH, 'r');
	ft_print_perm_char(mode, S_IWOTH, 'w');
	ft_print_perm_char(mode, S_IXOTH, 'x');
	ft_putchar(' ');
}

void	ft_print_time(time_t mtime)
{
	char	*str;

	str = ctime(&mtime);
	if (!str)
		return ;
	write(1, str + 4, 3);
	write(1, " ", 1);
	write(1, str + 8, 2);
	write(1, " ", 1);
	write(1, str + 11, 5);
}

void	ft_print_symlink(const char *path)
{
	char	buf[PATH_MAX];
	ssize_t	len;

	len = readlink(path, buf, sizeof(buf) - 1);
	if (len != -1)
	{
		buf[len] = '\0';
		ft_printf(" -> %s", buf);
	}
}
