/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:38:43 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/29 14:29:52 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	count(int n)
{
	int	c;

	c = 0;
	if (n <= 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static char	*ft_itoa(int n)
{
	int		c;
	char	*str;

	c = count(n);
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (0);
	if (n < 0)
		*str = '-';
	if (n == 0)
		*str = '0';
	str[c] = '\0';
	while (n)
	{
		c--;
		str[c] = absolute(n % 10) + 48;
		n /= 10;
	}
	return (str);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		size;

	s = ft_itoa(n);
	size = ft_putstr(s);
	free(s);
	return (size);
}
