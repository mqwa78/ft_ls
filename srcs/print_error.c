/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:57:14 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/22 13:57:59 by mqwa             ###   ########.fr       */
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
