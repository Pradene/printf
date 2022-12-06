/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:24:25 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/29 14:25:12 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putformated(va_list params, char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_putchar(va_arg(params, int));
	else if (c == 's')
		size += ft_putstr(va_arg(params, char *));
	else if (c == 'p')
		size += ft_putptr(va_arg(params, unsigned long long));
	else if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(params, int));
	else if (c == 'u')
		size += ft_putunbr(va_arg(params, unsigned int));
	else if (c == 'x' || c == 'X')
		size += ft_puthex(va_arg(params, unsigned int), c - 23);
	else if (c == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		size;
	va_list	params;

	i = 0;
	size = 0;
	va_start(params, s);
	while (s[i])
	{
		if (s[i] != '%')
			size += ft_putchar(s[i]);
		else
			size += ft_putformated(params, s[++i]);
		i++;
	}
	va_end(params);
	return (size);
}
