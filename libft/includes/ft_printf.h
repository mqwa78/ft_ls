/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:00:14 by mqwa              #+#    #+#             */
/*   Updated: 2026/04/24 22:53:29 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(const char *s);
int		ft_putupper_hexa(unsigned int n);
int		ft_putlower_hexa(unsigned int n);
int		ft_putaddr(void *addr);
int		ft_putnbr(int n);
int		ft_put_unsigned_n(unsigned int n);
int		ft_printf(const char *format, ...);

#endif
