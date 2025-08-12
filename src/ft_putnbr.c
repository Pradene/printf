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

int	ft_putnbr(int n) {
	char					buf[12];
	int						i;
	unsigned int	num;

	i = 11;
	buf[i] = '\0';
	if (n == 0) {
		buf[--i] = '0';
	} else {
		if (n < 0) {
			num = (unsigned int)(-n);
		} else {
			num = (unsigned int)n;
		}
		while (num) {
			buf[--i] = (num % 10) + '0';
			num /= 10;
		}
		if (n < 0) {
			buf[--i] = '-';
		}
	}
	return (ft_putstr(&buf[i]));
}

