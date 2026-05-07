/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 23:06:11 by mqwa              #+#    #+#             */
/*   Updated: 2026/05/07 01:16:39 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_widths(t_widths *w)
{
	w->nlink = 0;
	w->user = 0;
	w->group = 0;
	w->size = 0;
}

int	ft_nbrlen(long long n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_get_user_len(uid_t uid)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd)
		return (ft_strlen(pwd->pw_name));
	return (ft_nbrlen(uid));
}

int	ft_get_group_len(gid_t gid)
{
	struct group	*grp;

	grp = getgrgid(gid);
	if (grp)
		return (ft_strlen(grp->gr_name));
	return (ft_nbrlen(gid));
}

void	ft_calc_widths(t_list *files, t_widths *w)
{
	t_list	*head;
	t_file	*file;
	int		len;

	init_widths(w);
	head = files;
	while (head)
	{
		file = (t_file *)head->content;
		len = ft_nbrlen(file->st.st_nlink);
		if (len > w->nlink)
			w->nlink = len;
		len = ft_get_user_len(file->st.st_uid);
		if (len > w->user)
			w->user = len;
		len = ft_get_group_len(file->st.st_gid);
		if (len > w->group)
			w->group = len;
		len = ft_nbrlen(file->st.st_size);
		if (len > w->size)
			w->size = len;
		head = head->next;
	}
}
