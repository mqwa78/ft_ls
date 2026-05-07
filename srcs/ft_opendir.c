/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:06:48 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/25 00:11:08 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_process_subdirs(t_list *contents, t_opt *opt)
{
	t_list	*head;
	t_file	*file;

	head = contents;
	while (head)
	{
		file = (t_file *)head->content;
		if (!file->error && S_ISDIR(file->st.st_mode)
			&& ft_is_valid_dir(file->name))
		{
			ft_printf("\n%s:\n", file->path);
			ft_opendir(file->path, opt);
		}
		head = head->next;
	}
}

static void	ft_display_dir(t_list *contents, t_opt *opt)
{
	contents = ft_sort(contents, opt);
	ft_display(contents, opt, 1);
	if (opt->opt_rec)
		ft_process_subdirs(contents, opt);
	ft_lstclear(&contents, ft_free_file);
}

int	ft_read_dir(DIR *dir, const char *path, t_list **contents, t_opt *opt)
{
	struct dirent	*entry;
	char			*full_path;

	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_name[0] != '.' || opt->opt_a)
		{
			full_path = ft_build_full_path(path, entry->d_name);
			if (!full_path)
				return (1);
			if (ft_add_path(contents, full_path))
			{
				free(full_path);
				return (1);
			}
			free(full_path);
		}
		entry = readdir(dir);
	}
	return (0);
}

int	ft_opendir(const char *path, t_opt *opt)
{
	DIR				*dir;
	t_list			*contents;

	contents = NULL;
	dir = opendir(path);
	if (!dir)
		return (ft_print_dir_error(path));
	if (ft_read_dir(dir, path, &contents, opt))
	{
		closedir(dir);
		ft_lstclear(&contents, ft_free_file);
		return (1);
	}
	closedir(dir);
	if (contents)
		ft_display_dir(contents, opt);
	return (0);
}
