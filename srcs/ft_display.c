/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:13:35 by mqwa              #+#    #+#             */
/*   Updated: 2026/05/07 04:18:14 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_owner_group(t_file *file, t_widths *w)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(file->st.st_uid);
	if (pwd)
		ft_putstr(pwd->pw_name);
	else
		ft_putnbr(file->st.st_uid);
	ft_putnchar_fd(' ', w->user - ft_get_user_len(file->st.st_uid) + 1, 1);
	grp = getgrgid(file->st.st_gid);
	if (grp)
		ft_putstr(grp->gr_name);
	else
		ft_putnbr(file->st.st_gid);
	ft_putnchar_fd(' ', w->group - ft_get_group_len(file->st.st_gid) + 1, 1);
}

void	ft_display_long(t_list *files, int show_total)
{
	t_list		*head;
	t_file		*file;
	int			total;
	t_widths	widths;

	if (show_total)
	{
		total = 0;
		head = files;
		while (head)
		{
			file = (t_file *)head->content;
			total += file->st.st_blocks;
			head = head->next;
		}
		ft_printf("total %d\n", total / 2);
	}
	ft_calc_widths(files, &widths);
	head = files;
	while (head)
	{
		file = (t_file *)head->content;
		ft_print_long(file, &widths);
		head = head->next;
	}
}

static void	ft_display_simple(t_list *files)
{
	t_list	*head;
	t_file	*file;
	int		first;

	head = files;
	first = 1;
	while (head)
	{
		file = (t_file *)head->content;
		if (!first)
			ft_printf(" ");
		ft_printf("%s", file->name);
		first = 0;
		head = head->next;
	}
	if (!first)
		ft_printf("\n");
}

void	ft_display(t_list *files, t_opt *opt, int show_total)
{
	if (!files)
		return ;
	if (opt->opt_l)
		ft_display_long(files, show_total);
	else
		ft_display_simple(files);
}
