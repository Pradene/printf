/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:59:02 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/27 18:53:05 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s) {
	int	i;

	if (!s) {
		return (0);
	}
	i = 0;
	while (s[i]) {
		i++;
	}
	return (i);
}

int	ft_putchar(char c) {
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s) {
	if (!s) {
		return (ft_putstr("(null)"));
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
