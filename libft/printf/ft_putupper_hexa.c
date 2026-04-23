/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupper_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:08 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/18 13:52:36 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_unsigned_upperhexa(unsigned int n)
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

int	ft_putupper_hexa(unsigned int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_putupper_hexa(n / 16);
	ft_putchar(base[n % 16]);
	return (ft_count_unsigned_upperhexa(n));
}
