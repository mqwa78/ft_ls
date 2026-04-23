/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 07:53:06 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/22 14:21:26 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_cmp_time(t_file *a, t_file *b)
{
	if (a->st.st_mtime > b->st.st_mtime)
		return (-1);
	if (a->st.st_mtime < b->st.st_mtime)
		return (1);
	return (ft_strcmp(a->path, b->path));
}

void	ft_free_file(void *content)
{
	t_file	*file;

	file = (t_file *)content;
	if (file)
		free(file->path);
	free(file);
}

int	ft_add_path(t_list **paths, char *str)
{
	t_list	*node;
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (1);
	file->path = ft_strdup(str);
	if (!file->path)
		return (free(file), 1);
	if (lstat(str, &file->st) < 0)
		ft_memset(&file->st, 0, sizeof(struct stat));
	node = ft_lstnew(file);
	if (!node)
		return (free(file->path), free(file), 1);
	ft_lstadd_back(paths, node);
	return (0);
}
