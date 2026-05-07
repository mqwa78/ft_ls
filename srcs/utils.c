/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 07:53:06 by mqwa              #+#    #+#             */
/*   Updated: 2026/05/07 04:34:10 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_cmp_time(t_file *a, t_file *b)
{
	if (a->st.st_mtime > b->st.st_mtime)
		return (-1);
	if (a->st.st_mtime < b->st.st_mtime)
		return (1);
	if (a->st.st_mtim.tv_nsec > b->st.st_mtim.tv_nsec)
		return (-1);
	if (a->st.st_mtim.tv_nsec < b->st.st_mtim.tv_nsec)
		return (1);
	return (ft_strcmp(a->path, b->path));
}

void	ft_free_file(void *content)
{
	t_file	*file;

	file = (t_file *)content;
	if (!file)
		return ;
	if (file->path)
		free(file->path);
	if (file->name)
		free(file->name);
	free(file);
}

char	*ft_build_full_path(const char *parent, const char *name)
{
	char	*path;
	size_t	plen;
	size_t	nlen;
	int		need_slash;

	plen = ft_strlen(parent);
	nlen = ft_strlen(name);
	need_slash = (plen > 0 && parent[plen - 1] != '/');
	path = malloc(plen + nlen + need_slash + 1);
	if (!path)
		return (NULL);
	ft_strcpy(path, parent);
	if (need_slash)
		ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}

int	ft_is_valid_dir(const char *name)
{
	if (ft_strcmp(name, ".") == 0)
		return (0);
	if (ft_strcmp(name, "..") == 0)
		return (0);
	return (1);
}

void	ft_count_types(t_list *paths, int *files, int *dirs, int *errors)
{
	t_file	*file;

	*files = 0;
	*dirs = 0;
	*errors = 0;
	while (paths)
	{
		file = (t_file *)paths->content;
		if (file->error)
			(*errors)++;
		else if (S_ISDIR(file->st.st_mode))
			(*dirs)++;
		else
			(*files)++;
		paths = paths->next;
	}
}
