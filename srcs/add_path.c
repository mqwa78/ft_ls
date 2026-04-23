/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:48:28 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/23 12:08:27 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_extract_name(const char *path)
{
	int	i;
	int	end;

	if (!path || !*path)
		return (ft_strdup("."));
	i = ft_strlen(path) - 1;
	while (i > 0 && path[i] == '/')
		i--;
	end = i;
	if (i == 0 && path[i] == '/')
		return (ft_strdup("/"));
	while (i >= 0 && path[i] != '/')
		i--;
	return (ft_strndup(path + i + 1, end - i));
}

static int	ft_init_paths(t_file *file, char *str)
{
	file->path = ft_strdup(str);
	if (!file->path)
		return (1);
	file->name = ft_extract_name(str);
	if (!file->name)
	{
		free(file->path);
		return (1);
	}
	return (0);
}

static void	ft_init_stat(t_file *file, char *str)
{
	if (lstat(str, &file->st) < 0)
	{
		ft_memset(&file->st, 0, sizeof(struct stat));
		file->error = errno;
	}
	else
		file->error = 0;
}

int	ft_add_path(t_list **paths, char *str)
{
	t_list	*node;
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (1);
	if (ft_init_paths(file, str))
	{
		free(file);
		return (1);
	}
	ft_init_stat(file, str);
	node = ft_lstnew(file);
	if (!node)
	{
		ft_free_file(file);
		return (1);
	}
	ft_lstadd_back(paths, node);
	return (0);
}
