/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:00:57 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/29 14:32:53 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	power(int n, int pow) {
	int	nb;

	nb = 1;
	while (pow) {
		nb *= n;
		pow--;
	}
	return (nb);
}

static int	uint_len(unsigned int n) {
	int	size;

	size = 0;
	while (n) {
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_putunbr(unsigned int n) {
	int		size;
	int		i;
	char	c;

	if (n == 0) {
		return (ft_putchar('0'));
	}
	size = uint_len(n);
	i = size - 1;
	while (i >= 0) {
		c = n / power(10, i) + '0';
		n = n - power(10, i) * (c - 48);
		write(1, &c, 1);
		i--;
	}
	return (size);
}
