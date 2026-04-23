/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:40 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/18 13:51:48 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_unsigned_digits(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_put_unsigned_n(unsigned int n)
{
	unsigned long	nb;

	nb = n;
	if (nb >= 10)
		ft_put_unsigned_n(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (ft_count_unsigned_digits(n));
}
