/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:25:28 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/29 14:31:12 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_char(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

static int	ft_puthexa(unsigned long long n)
{
	int		c;
	char	*s;

	c = count_char(n);
	s = malloc(sizeof(char) * (c + 1));
	if (!s)
		return (0);
	if (n == 0)
		s[0] = '0';
	s[c] = '\0';
	while (n)
	{
		c--;
		if (n % 16 < 10)
			s[c] = n % 16 + '0';
		else
			s[c] = n % 16 - 10 + 'a';
		n /= 16;
	}
	c = ft_putstr(s);
	free(s);
	return (c);
}

int	ft_putptr(unsigned long long n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_putstr("(nil)");
	else
	{
		size += write(1, "0x", 2);
		size += ft_puthexa(n);
	}
	return (size);
}
