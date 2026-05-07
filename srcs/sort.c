/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:37:18 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/23 16:23:13 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*ft_sorted_insert_time(t_list *sorted, t_list *new_node)
{
	t_list	*curr;
	t_file	*new_f;

	new_f = new_node->content;
	if (!sorted || ft_cmp_time(new_f, sorted->content) < 0)
	{
		new_node->next = sorted;
		return (new_node);
	}
	curr = sorted;
	while (curr->next && ft_cmp_time(new_f, curr->next->content) >= 0)
		curr = curr->next;
	new_node->next = curr->next;
	curr->next = new_node;
	return (sorted);
}

static t_list	*ft_sorted_insert_ascii(t_list *sorted, t_list *new_node)
{
	t_list	*curr;
	t_file	*new_f;

	new_f = new_node->content;
	if (!sorted || ft_strcmp(new_f->path,
			((t_file *)sorted->content)->path) < 0)
	{
		new_node->next = sorted;
		return (new_node);
	}
	curr = sorted;
	while (curr->next && ft_strcmp(new_f->path,
			((t_file *)curr->next->content)->path) >= 0)
		curr = curr->next;
	new_node->next = curr->next;
	curr->next = new_node;
	return (sorted);
}

static t_list	*sort_list(t_list *head, t_list *(*insert)(t_list *, t_list *))
{
	t_list	*sorted;
	t_list	*current;
	t_list	*next;

	sorted = NULL;
	current = head;
	while (current)
	{
		next = current->next;
		sorted = insert(sorted, current);
		current = next;
	}
	return (sorted);
}

t_list	*ft_reverse(t_list *head)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = head;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

t_list	*ft_sort(t_list *list, t_opt *opt)
{
	t_list	*sorted;

	if (!list)
		return (NULL);
	if (opt->opt_t)
		sorted = sort_list(list, ft_sorted_insert_time);
	else
		sorted = sort_list(list, ft_sorted_insert_ascii);
	if (opt->opt_r)
		sorted = ft_reverse(sorted);
	return (sorted);
}
