/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:30:45 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/29 14:29:27 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

int	ft_puthex(unsigned long long n)
{
	int		c;
	char	*s;

	c = hex_len(n);
	s = malloc(sizeof(char) * (c + 1));
	if (!s)
		return (0);
	if (n == 0)
		s[0] = '0';
	s[c] = '\0';
	while (n && c)
	{
		c--;
		if (n % 16 < 10)
			s[c] = n % 16 + '0';
		else
			s[c] = n % 16 - 10 + 'A';
		n /= 16;
	}
	c = ft_putstr(s);
	free(s);
	return (c);
}
