/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:21:30 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/18 13:52:28 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	size;

	size = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[size])
	{
		write(1, &s[size], 1);
		size++;
	}
	return (size);
}
