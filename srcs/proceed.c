/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:55:22 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/25 00:10:39 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_sort_and_display_files(t_list **files, t_opt *opt)
{
	*files = ft_sort(*files, opt);
	ft_display(*files, opt, 0);
	ft_lstclear(files, NULL);
}

static void	ft_process_files(t_list *paths, t_opt *opt)
{
	t_list	*files;
	t_list	*head;
	t_file	*file;
	t_list	*node;

	files = NULL;
	head = paths;
	while (head)
	{
		file = (t_file *)head->content;
		if (!file->error && !S_ISDIR(file->st.st_mode))
		{
			node = ft_lstnew(file);
			if (!node)
			{
				ft_lstclear(&files, NULL);
				return ;
			}
			ft_lstadd_back(&files, node);
		}
		head = head->next;
	}
	if (files)
		ft_sort_and_display_files(&files, opt);
}

static void	ft_sort_and_open_dirs(t_list **dirs, t_opt *opt, int show_name)
{
	t_list	*head;
	t_file	*file;
	int		first;

	*dirs = ft_sort(*dirs, opt);
	head = *dirs;
	first = 1;
	while (head)
	{
		file = (t_file *)head->content;
		if (show_name)
		{
			if (!first)
				ft_printf("\n");
			ft_printf("%s:\n", file->path);
			first = 0;
		}
		ft_opendir(file->path, opt);
		head = head->next;
	}
	ft_lstclear(dirs, NULL);
}

static void	ft_process_dirs(t_list *paths, t_opt *opt, int show_name)
{
	t_list	*dirs;
	t_list	*head;
	t_file	*file;
	t_list	*node;

	dirs = NULL;
	head = paths;
	while (head)
	{
		file = (t_file *)head->content;
		if (!file->error && S_ISDIR(file->st.st_mode))
		{
			node = ft_lstnew(file);
			if (!node)
			{
				ft_lstclear(&dirs, NULL);
				return ;
			}
			ft_lstadd_back(&dirs, node);
		}
		head = head->next;
	}
	if (dirs)
		ft_sort_and_open_dirs(&dirs, opt, show_name);
}

int	ft_proceed(t_opt *opt, t_list *paths)
{
	int	file_count;
	int	dir_count;
	int	error_count;
	int	show_dir_names;

	ft_count_types(paths, &file_count, &dir_count, &error_count);
	if (dir_count > 1)
		show_dir_names = 1;
	else if (dir_count == 1 && (file_count > 0 || error_count > 0))
		show_dir_names = 1;
	else
		show_dir_names = 0;
	ft_process_errors(paths);
	ft_process_files(paths, opt);
	if (file_count && dir_count)
		ft_printf("\n");
	ft_process_dirs(paths, opt, show_dir_names);
	if (error_count > 0)
		return (1);
	return (0);
}
