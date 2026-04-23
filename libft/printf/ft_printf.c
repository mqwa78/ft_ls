/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:02:06 by mamahtal          #+#    #+#             */
/*   Updated: 2023/11/18 14:06:19 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putargs(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, const char *)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_put_unsigned_n(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putlower_hexa(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_putupper_hexa(va_arg(args, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count_char;

	va_start(args, format);
	count_char = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count_char += ft_putargs(args, format[i + 1]);
			i++;
		}
		else
			count_char += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count_char);
}
