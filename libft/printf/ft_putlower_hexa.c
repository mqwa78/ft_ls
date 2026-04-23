/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlower_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:16:39 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/18 14:06:30 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_unsigned_lowerhexa(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	ft_putlower_hexa(unsigned int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_putlower_hexa(n / 16);
	ft_putchar(base[n % 16]);
	return (ft_count_unsigned_lowerhexa(n));
}
