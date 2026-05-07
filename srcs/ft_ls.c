/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:16:04 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/23 16:16:43 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_parse_option(char *arg, t_opt *opt)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'l')
			opt->opt_l = 1;
		else if (arg[i] == 'r')
			opt->opt_r = 1;
		else if (arg[i] == 'R')
			opt->opt_rec = 1;
		else if (arg[i] == 'a')
			opt->opt_a = 1;
		else if (arg[i] == 't')
			opt->opt_t = 1;
		else
			return (ft_error_option(arg[i]));
		i++;
	}
	return (0);
}

int	ft_build_paths(int ac, char **av, t_opt *opt, t_list **paths)
{
	int	i;
	int	end_opt;

	i = 1;
	end_opt = 0;
	while (i < ac)
	{
		if (!end_opt && !ft_strcmp(av[i], "--"))
		{
			end_opt = 1;
			i++;
			continue ;
		}
		if (!end_opt && av[i][0] == '-' && av[i][1])
		{
			if (ft_parse_option(av[i], opt))
				return (1);
		}
		else if (ft_add_path(paths, av[i]))
			return (1);
		i++;
	}
	if (!*paths && ft_add_path(paths, "."))
		return (1);
	return (0);
}

int	ft_ls(int ac, char **av, t_opt *opt)
{
	t_list	*paths;
	int		ret;

	paths = NULL;
	if (ft_build_paths(ac, av, opt, &paths))
	{
		ft_lstclear(&paths, ft_free_file);
		return (EXIT_STATUS);
	}
	ret = ft_proceed(opt, paths);
	ft_lstclear(&paths, ft_free_file);
	if (ret)
		return (EXIT_STATUS);
	return (EXIT_SUCCESS);
}
