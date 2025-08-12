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

int	ft_putptr(unsigned long long n) {
	int	size;

	size = 0;
	if (n == 0) {
		size += ft_putstr("(nil)");
	} else {
		size += write(1, "0x", 2);
		size += ft_puthex(n);
	}
	return (size);
}
