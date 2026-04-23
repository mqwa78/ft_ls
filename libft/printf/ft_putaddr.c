/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:47:57 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/18 13:52:05 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_long_digits(unsigned long long n)
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

static void	ft_putaddr_hexa(unsigned long long nb)
{
	const char	*basehexa;

	basehexa = "0123456789abcdef";
	if (nb >= 16)
		ft_putaddr_hexa(nb / 16);
	ft_putchar(basehexa[nb % 16]);
}

int	ft_putaddr(void *addr)
{
	if (!addr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_putaddr_hexa((unsigned long long)addr);
	return (ft_count_long_digits((unsigned long long)addr) + 2);
}
