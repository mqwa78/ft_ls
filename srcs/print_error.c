/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:57:14 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/23 17:20:40 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_error_option(char c)
{
	ft_putstr_fd("ft_ls: invalid option -- '", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("'", 2);
	ft_putendl_fd("Try 'ft_ls --help' for more information.", 2);
	return (1);
}

int	ft_print_dir_error(const char *path)
{
	ft_putstr_fd("ft_ls: cannot open directory '", 2);
	ft_putstr_fd((char *)path, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}

void	ft_print_file_error(t_file *file)
{
	ft_putstr_fd("ft_ls: cannot access '", 2);
	ft_putstr_fd(file->path, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(strerror(file->error), 2);
}

void	ft_process_errors(t_list *paths)
{
	t_list	*head;
	t_file	*file;

	head = paths;
	while (head)
	{
		file = (t_file *)head->content;
		if (file->error)
			ft_print_file_error(file);
		head = head->next;
	}
}
